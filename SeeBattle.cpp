//NCURSES
//initscr(); start
//endwin(); end
//printw(); print
//getch(); input
//clear(); clear
//start_color(); startcolor
//attron(COLOR_PAIR(index));
//attroff(COLOR_PAIR(index));
//init_pair(index, COLOR_WHITE, COLOR_BLACK);

// Bibliotheks

#include "bibliothek.cpp"

//Namespcases

using namespace std;

// Const
const int HEIGHT = 10;
const int WIDTH = 11;
char first_player_field[HEIGHT][WIDTH];
char second_player_field[HEIGHT][WIDTH];
char first_player_battle_field[HEIGHT][WIDTH];
char second_player_battle_field[HEIGHT][WIDTH];
int point_y = 1;
int point_x = 1;
bool gorisontal = true;
bool vertical = false;
bool ship_4x = true;
bool ships_3x = true;
bool ships_2x = true;
bool ships_1x = true;
int ships_3x_num = 2;
int ships_2x_num = 3;
int ships_1x_num = 4;
bool GAME = true;
bool turn = true;
int first_points = 0;
int second_points = 0;

// Declaration of Functions 

void building_menu();
void colors_create();
void create_fields();
void map_for_first_player();
void building_map_first_player();
void mini_reset();
void building_map_second_player();
void map_for_second_player();
void reset();
void building_battle_map_first_player();
void battle_map_for_first_player();
void battle_map_for_second_player();
void building_battle_map_second_player();

// Main Function

int main(void) {
  
    initscr();
    colors_create();
    building_menu();
    create_fields();
    while (ship_4x == true || ships_3x == true || ships_2x == true || ships_1x == true) {
        map_for_first_player();
    } map_for_first_player();
    printw("\n\t\tField is ready, press enter to continue");
    reset();
    getch();

    while (ship_4x == true || ships_3x == true || ships_2x == true || ships_1x == true) {
        map_for_second_player();
    } map_for_second_player();
    printw("\n\t\tField is ready, press enter to continue");

    while (GAME) {
        turn = true;
        while (turn && GAME) {
            battle_map_for_first_player();
        }
        turn = true;
        while (turn && GAME) {
            battle_map_for_second_player();
        }
    }

    clear();
    if (first_points > second_points) {
        printw("\n\t\t\tFIRST PLAYER WIN !");
    } else {
        printw("\n\t\t\tSECOND PLAYER WIN !");
    }

    getch();
    endwin();

    return 0;
}

// Functions

void building_menu() {
    attron(COLOR_PAIR(1));
    printw("\t\t\tSee Battle\n\t\t  Press enter to start");
    attroff(COLOR_PAIR(1));
    getch();
}

void colors_create() {
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);

}

void create_fields() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 2) {
                first_player_field[i][j] = '#';
                second_player_field[i][j] = '#';
                first_player_battle_field[i][j] = '#';
                second_player_battle_field[i][j] = '#';
            } else {
                first_player_field[i][j] = ' ';
                second_player_field[i][j] = ' ';
                first_player_battle_field[i][j] = ' ';
                second_player_battle_field[i][j] = ' ';
            }
        }
    }
}

void map_for_first_player() {
    
    building_map_first_player();

    printw("\n");
    if (ship_4x)
        printw("\n\t\t    Press 1 for 4x Ship");
    if (ships_3x)
        printw("\n\t\t    Press 2 for 3x Ship");
    if (ships_2x)
        printw("\n\t\t    Press 3 for 2x Ship");
    if (ships_1x)
        printw("\n\t\t    Press 4 for 1x Ship");
    if (ship_4x || ships_3x || ships_2x || ships_1x)
        printw("\n\t\t      Your choise - ");

    int choise = '-';
    if (choise == '-' && (ship_4x == true || ships_3x == true || ships_2x == true || ships_1x == true)) {
        choise = getch();
    }

    int move = '-';

    switch (choise) {
        case '1':
            if (ship_4x)
            while (move != 10) {

                     if (gorisontal == true && vertical == false) {
                         if (first_player_field[point_y][point_x] != '0'
                            && first_player_field[point_y][point_x + 1] != '0'
                            && first_player_field[point_y][point_x + 2] != '0'
                            && first_player_field[point_y][point_x + 3] != '0'
                            && first_player_field[point_y][point_x] != '+'
                            && first_player_field[point_y][point_x + 1] != '+'
                            && first_player_field[point_y][point_x + 2] != '+'
                            && first_player_field[point_y][point_x + 3] != '+') {
                            for (int i = 0; i < 4; i++) {
                                first_player_field[point_y][point_x + i] = 'O';
                            }
                         } else {
                            while(first_player_field[point_y][point_x] == '+'
                                  || first_player_field[point_y][point_x + 1] == '+'
                                  || first_player_field[point_y][point_x + 2] == '+'
                                  || first_player_field[point_y][point_x + 3] == '+'
                                  || first_player_field[point_y][point_x] == '0'
                                  || first_player_field[point_y][point_x + 1] == '0'
                                  || first_player_field[point_y][point_x + 2] == '0'
                                  || first_player_field[point_y][point_x + 3] == '0') {
                                point_x++;
                                if (point_x == WIDTH - 5) {
                                    point_y++;
                                    point_x = 1;
                                }
                            }
                            for (int i = 0; i < 4; i++) {
                                first_player_field[point_y][point_x + i] = 'O';
                            }
                         
                         }
                      } else if (vertical == true && gorisontal == false) {
                         for (int i = 0; i < 4; i++) {
                             first_player_field[point_y + i][point_x] = 'O';
                         }
                     }
                 

                building_map_first_player();
                move = getch();
                switch (move) {
                    case 's':
                        
                        if (point_y + 2 < HEIGHT && gorisontal == true) {
                                 
                                if (first_player_field[point_y + 1][point_x] == ' '
                                   && first_player_field[point_y + 1][point_x + 1] == ' '
                                   && first_player_field[point_y + 1][point_x + 2] == ' '
                                   && first_player_field[point_y + 1][point_x + 3] == ' ') {
                                    for (int i = 0; i < 4; i++) {
                                        first_player_field[point_y][point_x + i] = ' ';
                                        first_player_field[point_y + 1][point_x + i] = 'O';
                                    }
                                    point_y += 1;
                                } else {
                                    int j = point_y + 1;
                                    while (j + 2 < HEIGHT) {
                                        if (first_player_field[j + 1][point_x] == ' '
                                           && first_player_field[j + 1][point_x + 1] == ' '
                                           && first_player_field[j + 1][point_x + 2] == ' '
                                           && first_player_field[j + 1][point_x + 3] == ' ') {
                                            for (int i = 0; i < 4; i++) {
                                                first_player_field[point_y][point_x + i] = ' ';
                                                first_player_field[j + 1][point_x + i] = 'O';
                                            }         
                                            point_y = j + 1;
                                            j = HEIGHT;
                                        }
                                        j++;
                                    }
                                }
                        } else if (point_y + 5 != HEIGHT && vertical == true) {
                            
                            if (first_player_field[point_y + 4][point_x] == ' ') {
                                for (int i = 0; i < 4; i++) {
                                    first_player_field[point_y + i + 1][point_x] = 'O'; 
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_y += 1;
                            } else {
                                int j = point_y + 5;
                                while (j + 2 < HEIGHT) {
                                    if (first_player_field[j + 1][point_x] == ' '
                                       && first_player_field[j + 2][point_x] == ' '
                                       && first_player_field[j + 3][point_x] == ' '
                                       && first_player_field[j + 4][point_x] == ' ') {
                                        for (int i = 0; i < 4; i++) {
                                            first_player_field[j + i + 1][point_x] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';     
                                        }
                                        point_y = j + 1;
                                        j = HEIGHT;
                                    }
                                    j++;
                                }
                            } 
                        }

                        break;
                    case 'w':

                         if (point_y - 1 != 0 && gorisontal == true) {

                                if (first_player_field[point_y - 1][point_x] == ' '
                                   && first_player_field[point_y - 1][point_x + 1] == ' '
                                   && first_player_field[point_y - 1][point_x + 2] == ' '
                                   && first_player_field[point_y - 1][point_x + 3] == ' ') {
                                    for (int i = 0; i < 4; i++) {
                                        first_player_field[point_y][point_x + i] = ' ';
                                        first_player_field[point_y - 1][point_x + i] = 'O';
                                    }
                                    point_y -= 1;
                                } else {
                                    int j = point_y - 1;
                                    while (j - 1 > 0) {
                                        if (first_player_field[j - 1][point_x] == ' '
                                           && first_player_field[j - 1][point_x + 1] == ' '
                                           && first_player_field[j - 1][point_x + 2] == ' '
                                           && first_player_field[j - 1][point_x + 3] == ' ') {
                                            for (int i = 0; i < 4; i++) {
                                                first_player_field[point_y][point_x + i] = ' ';
                                                first_player_field[j - 1][point_x + i] = 'O';
                                            }
                                            point_y = j - 1;
                                            j = 0;
                                        }
                                        j--;
                                    }
                                }
                            
                        } else if (point_y - 1 != 0 && vertical == true) {
                            
                            if (first_player_field[point_y - 1][point_x] == ' ') {
                                for (int i = 0; i < 4; i++) {
                                    first_player_field[point_y + i - 1][point_x] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_y -= 1;
                            } else {
                                int j = point_y - 1;
                                while(j - 1 > 0) {
                                    if (first_player_field[j - 1][point_x] == ' '
                                       && first_player_field[j - 2][point_x] == ' '
                                       && first_player_field[j - 3][point_x] == ' '
                                       && first_player_field[j - 4][point_x] == ' ') {
                                        for (int i = 0; i < 4; i++) {
                                            first_player_field[j - i - 1][point_x] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';
                                        }
                                        point_y = j - 4;
                                        j = 0;
                                    }
                                    j--;
                                }
                                
                            }
                        } 
                        
                        break;
                    case 'd':

                        if (point_x + 4 != WIDTH - 2 && gorisontal == true) {
                                
                            if (first_player_field[point_y][point_x + 4] == ' ') {
                                for (int i = 3; i > -1; i--) {
                                    first_player_field[point_y][point_x + i + 1] = 'O';
                                    first_player_field[point_y][point_x + i] = ' ';
                                }
                                point_x += 1;
                            } else {
                                int j = point_x + 4;
                                while (j + 4 < WIDTH) {
                                    if (first_player_field[point_y][j] == ' '
                                       && first_player_field[point_y][j + 1] == ' '
                                       && first_player_field[point_y][j + 2] == ' '
                                       && first_player_field[point_y][j + 3] == ' ') {
                                        for (int i = 3; i > -1; i--) {
                                             first_player_field[point_y][j + i] = 'O';
                                             first_player_field[point_y][point_x + i] = ' ';
                                        }
                                        point_x = j;
                                        j = WIDTH;
                                    }
                                    j++;
                                } 
                            }
                        } else if (point_x + 1 != WIDTH - 2 && vertical == true) {
                            
                            if (first_player_field[point_y][point_x + 1] == ' '
                               && first_player_field[point_y + 1][point_x + 1] == ' '
                               && first_player_field[point_y + 2][point_x + 1] == ' '
                               && first_player_field[point_y + 3][point_x + 1] == ' ') {
                                for (int i = 0; i < 4; i++) {
                                    first_player_field[point_y + i][point_x + 1] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_x += 1;
                            } else {
                                int j = point_x + 1;
                                while (j + 2 < WIDTH) {
                                    if (first_player_field[point_y][j] == ' '
                                       && first_player_field[point_y + 1][j] == ' '
                                       && first_player_field[point_y + 2][j] == ' '
                                       && first_player_field[point_y + 3][j] == ' ') {
                                        for (int i = 0; i < 4; i++) {
                                            first_player_field[point_y + i][point_x] = ' ';
                                            first_player_field[point_y + i][j] = 'O';
                                        }
                                        point_x = j;
                                        j = WIDTH;
                                    }    
                                    j++;
                                }
                            }
                            
                        }

                        break;
                    case 'a':

                        if (point_x - 1 != 0 && gorisontal == true) {
                            if (first_player_field[point_y][point_x - 1] == ' ') {    
                                for (int i = 0; i < 4; i++) {
                                    first_player_field[point_y][point_x + i - 1] = 'O';
                                    first_player_field[point_y][point_x + i] = ' ';
                                }
                                point_x -= 1;
                            } else {
                                int j = point_x;
                                while (j - 1 > 0) {
                                    if (first_player_field[point_y][j - 1] == ' '
                                       && first_player_field[point_y][j - 2] == ' '
                                       && first_player_field[point_y][j - 3] == ' '
                                       && first_player_field[point_y][j - 4] == ' ') {
                                        for (int i = 0; i < 4; i++) { 
                                            first_player_field[point_y][point_x + i] = ' ';
                                            first_player_field[point_y][j - i - 1] = 'O';
                                        }
                                        point_x = j - 4;
                                        j = 0;
                                    }

                                    j--;
                                }
                            
                            }
                        } else if (point_x - 1 != 0 && vertical == true) {
                            if (first_player_field[point_y][point_x - 1] == ' '
                               && first_player_field[point_y + 1][point_x - 1] == ' '
                               && first_player_field[point_y + 2][point_x - 1] == ' '
                               && first_player_field[point_y + 3][point_x - 1] == ' ') {
                                for (int i = 0; i < 4; i++) {
                                    first_player_field[point_y + i][point_x - 1] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }  
                                point_x -= 1;
                            }
                         else {
                                int j = point_x - 1;
                                while (j - 1 > 0) {
                                    if (first_player_field[point_y][j] == ' '
                                        && first_player_field[point_y + 1][j] == ' '
                                        && first_player_field[point_y + 2][j] == ' '
                                        && first_player_field[point_y + 3][j] == ' ') {
                                          for (int i = 0; i < 4; i++) { 
                                            first_player_field[point_y + i][j] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';     
                                        }
                                        point_x = j;
                                        j = 0;
                                    }
                                    j--; 
                                }
                            }
                        }

                        break;
                    case 'f':

                        if (gorisontal == true && point_y < HEIGHT - 4
                           && first_player_field[point_y + 1][point_x] == ' '
                           && first_player_field[point_y + 2][point_x] == ' '
                           && first_player_field[point_y + 3][point_x] == ' ') {
                            gorisontal = false;
                            vertical = true;
                            for (int i = 0; i < 4; i++) {
                                    first_player_field[point_y + i][point_x] = 'O';
                                    if (i != 3) {
                                        first_player_field[point_y][point_x + i + 1] = ' ';
                                    }
                            }
                        } else if (vertical == true && point_x < WIDTH - 5
                                  && first_player_field[point_y][point_x + 1] == ' '
                                  && first_player_field[point_y][point_x + 2] == ' '
                                  && first_player_field[point_y][point_x + 3] == ' ') {
                            gorisontal = true;
                            vertical = false;
                            for (int i = 0; i < 4; i++) {
                                first_player_field[point_y][point_x + i] = 'O';
                                if (i != 3) {
                                    first_player_field[point_y + i + 1][point_x] = ' ';
                                }
                            }
                        }

                        break;
                    case 10:
                        
                        if (gorisontal == true) {
                            for (int i = 0; i < 4; i++) {
                                first_player_field[point_y][point_x + i] = '0';
                                if (first_player_field[point_y + 1][point_x] != '#')
                                    first_player_field[point_y + 1][point_x + i] = '+';
                                if (first_player_field[point_y - 1][point_x] != '#')
                                    first_player_field[point_y - 1][point_x + i] = '+';

                                if (first_player_field[point_y][point_x - 1] != '#') {
                                    first_player_field[point_y][point_x - 1] = '+';
                                    if (first_player_field[point_y - 1][point_x - 1] != '#')
                                        first_player_field[point_y - 1][point_x - 1] = '+';
                                    if (first_player_field[point_y + 1][point_x - 1] != '#')
                                        first_player_field[point_y + 1][point_x - 1] = '+';
                                }
                                if (first_player_field[point_y][point_x + 4] != '#') {
                                    first_player_field[point_y][point_x + 4] = '+';
                                    if (first_player_field[point_y - 1][point_x + 4] != '#')
                                        first_player_field[point_y - 1][point_x + 4] = '+';
                                    if (first_player_field[point_y + 1][point_x + 4] != '#')
                                        first_player_field[point_y + 1][point_x + 4] = '+';
                                }
                                
                            }
                        } else {
                            for (int i = 0; i < 4; i++) {
                                first_player_field[point_y + i][point_x] = '0';
                                if (first_player_field[point_y][point_x - 1] != '#')
                                    first_player_field[point_y + i][point_x - 1] = '+';
                                if (first_player_field[point_y][point_x + 1] != '#')
                                    first_player_field[point_y + i][point_x + 1] = '+';
   
                                if (first_player_field[point_y - 1][point_x] != '#') {
                                    first_player_field[point_y - 1][point_x] = '+';
                                    if (first_player_field[point_y - 1][point_x - 1] != '#')
                                        first_player_field[point_y - 1][point_x - 1] = '+';
                                    if (first_player_field[point_y - 1][point_x + 1] != '#')
                                        first_player_field[point_y - 1][point_x + 1] = '+';
                                }
                                if (first_player_field[point_y + 4][point_x] != '#') {
                                    first_player_field[point_y + 4][point_x] = '+';
                                    if (first_player_field[point_y + 4][point_x - 1] != '#')
                                        first_player_field[point_y + 4][point_x - 1] = '+';
                                    if (first_player_field[point_y + 4][point_x + 1] != '#')
                                        first_player_field[point_y + 4][point_x + 1] = '+';
                                }
                            }
                        }
                        ship_4x = false;   

                        break;
                }
            }
            break;


        case '2':

            if (ships_3x)
            while (move != 10) {
               

                    if (gorisontal == true && vertical == false) {
                        if (first_player_field[point_y][point_x] != '0'
                           && first_player_field[point_y][point_x + 1] != '0'
                           && first_player_field[point_y][point_x + 2] != '0'
                           && first_player_field[point_y][point_x] != '+'
                           && first_player_field[point_y][point_x + 1] != '+'
                           && first_player_field[point_y][point_x + 2] != '+') {
                            for (int i = 0; i < 3; i++) {
                                first_player_field[point_y][point_x + i] = 'O';
                            }
                        } else {
                            while(first_player_field[point_y][point_x] == '+'
                                 || first_player_field[point_y][point_x + 1] == '+'
                                 || first_player_field[point_y][point_x + 2] == '+'
                                 || first_player_field[point_y][point_x] == '0'
                                 || first_player_field[point_y][point_x + 1] == '0'
                                 || first_player_field[point_y][point_x + 2] == '0') {
                               point_x++;
                               if (point_x == WIDTH - 4) {
                                   point_y++;
                                   point_x = 1;
                               }
                           }
                           for (int i = 0; i < 3; i++) {
                               first_player_field[point_y][point_x + i] = 'O';
                           }
                        }
                     } else if (vertical == true && gorisontal == false) {
                        for (int i = 0; i < 3; i++) {
                            first_player_field[point_y + i][point_x] = 'O';
                        }
                    }
                    

                building_map_first_player();
                move = getch();
                switch (move) {
                    case 's':

                        if (point_y + 2 < HEIGHT && gorisontal == true) {

                                if (first_player_field[point_y + 1][point_x] == ' '
                                   && first_player_field[point_y + 1][point_x + 1] == ' '
                                   && first_player_field[point_y + 1][point_x + 2] == ' ') {
                                    for (int i = 0; i < 3; i++) {
                                        first_player_field[point_y][point_x + i] = ' ';
                                        first_player_field[point_y + 1][point_x + i] = 'O';
                                    }
                                    point_y += 1;
                                } else {
                                    int j = point_y + 1;
                                    while (j + 2 < HEIGHT) {
                                        if (first_player_field[j + 1][point_x] == ' '
                                           && first_player_field[j + 1][point_x + 1] == ' '
                                           && first_player_field[j + 1][point_x + 2] == ' ') {
                                            for (int i = 0; i < 3; i++) {
                                                first_player_field[point_y][point_x + i] = ' ';
                                                first_player_field[j + 1][point_x + i] = 'O';
                                            }         
                                            point_y = j + 1;
                                            j = HEIGHT; 
                                        }
                                        j++;
                                    }
                                }
                        } else if (point_y + 4 != HEIGHT && vertical == true) {
                            
                            if (first_player_field[point_y + 3][point_x] == ' ') {
                                for (int i = 0; i < 3; i++) {
                                    first_player_field[point_y + i + 1][point_x] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }   
                                point_y += 1;
                            } else {
                                int j = point_y + 4;
                                while (j + 2 < HEIGHT) {
                                    if (first_player_field[j + 1][point_x] == ' '
                                       && first_player_field[j + 2][point_x] == ' '
                                       && first_player_field[j + 3][point_x] == ' ') {
                                        for (int i = 0; i < 3; i++) {
                                            first_player_field[j + i + 1][point_x] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';
                                        }
                                        point_y = j + 1;
                                        j = HEIGHT;
                                    }
                                    j++;
                                }
                            }
                        }

                        break;
                    case 'w':

                        if (point_y - 1 != 0 && gorisontal == true) {

                                if (first_player_field[point_y - 1][point_x] == ' '
                                   && first_player_field[point_y - 1][point_x + 1] == ' '
                                   && first_player_field[point_y - 1][point_x + 2] == ' ') {
                                    for (int i = 0; i < 3; i++) {
                                        first_player_field[point_y][point_x + i] = ' ';
                                        first_player_field[point_y - 1][point_x + i] = 'O';
                                    }
                                    point_y -= 1;
                                } else {
                                    int j = point_y - 1;
                                    while (j - 1 > 0) {
                                        if (first_player_field[j - 1][point_x] == ' '
                                           && first_player_field[j - 1][point_x + 1] == ' '
                                           && first_player_field[j - 1][point_x + 2] == ' ') {
                                            for (int i = 0; i < 3; i++) {
                                                first_player_field[point_y][point_x + i] = ' ';
                                                first_player_field[j - 1][point_x + i] = 'O';
                                            }
                                            point_y = j - 1;
                                            j = 0;
                                        }
                                        j--;
                                    }
                                }

                        } else if (point_y - 1 != 0 && vertical == true) {
                            
                            if (first_player_field[point_y - 1][point_x] == ' ') {
                                for (int i = 0; i < 3; i++) {
                                    first_player_field[point_y + i - 1][point_x] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_y -= 1;
                            } else {
                                int j = point_y - 1;
                                while(j - 1 > 0) {
                                    if (first_player_field[j - 1][point_x] == ' '
                                       && first_player_field[j - 2][point_x] == ' '
                                       && first_player_field[j - 3][point_x] == ' ') {
                                        for (int i = 0; i < 3; i++) {
                                            first_player_field[j - i - 1][point_x] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';
                                        }
                                        point_y = j - 3;
                                        j = 0;
                                    }
                                    j--;
                                }
                            }
                        }

                        break;
                    case 'd':
                        
                        if (point_x + 3 != WIDTH - 2 && gorisontal == true) {

                            if (first_player_field[point_y][point_x + 3] == ' ') {
                                for (int i = 2; i > -1; i--) {
                                    first_player_field[point_y][point_x + i + 1] = 'O';
                                    first_player_field[point_y][point_x + i] = ' ';
                                }
                                point_x += 1;
                            } else {
                                int j = point_x + 3;
                                while (j + 3 < WIDTH) {
                                    if (first_player_field[point_y][j] == ' '
                                       && first_player_field[point_y][j + 1] == ' '
                                       && first_player_field[point_y][j + 2] == ' ') {
                                        for (int i = 2; i > -1; i--) {
                                             first_player_field[point_y][j + i] = 'O';
                                             first_player_field[point_y][point_x + i] = ' ';
                                        }
                                        point_x = j;
                                        j = WIDTH;
                                    }
                                    j++;
                                }
                            }
                        } else if (point_x + 1 != WIDTH - 2 && vertical == true) {

                            if (first_player_field[point_y][point_x + 1] == ' '
                               && first_player_field[point_y + 1][point_x + 1] == ' '
                               && first_player_field[point_y + 2][point_x + 1] == ' ') {
                                for (int i = 0; i < 3; i++) {
                                    first_player_field[point_y + i][point_x + 1] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_x += 1;
                            } else {
                                int j = point_x + 1;
                                while (j + 2 < WIDTH) {
                                    if (first_player_field[point_y][j] == ' '
                                       && first_player_field[point_y + 1][j] == ' '
                                       && first_player_field[point_y + 2][j] == ' ') {
                                        for (int i = 0; i < 3; i++) {
                                            first_player_field[point_y + i][point_x] = ' ';
                                            first_player_field[point_y + i][j] = 'O';
                                        }
                                        point_x = j;
                                        j = WIDTH;
                                    }
                                    j++;
                                }
                            }
                        }

                        break;
                    case 'a':

                        if (point_x - 1 != 0 && gorisontal == true) {
                            if (first_player_field[point_y][point_x - 1] == ' ') {
                                for (int i = 0; i < 3; i++) {
                                    first_player_field[point_y][point_x + i - 1] = 'O';
                                    first_player_field[point_y][point_x + i] = ' ';
                                }
                                point_x -= 1;
                            } else {
                                int j = point_x;
                                while (j - 1 > 0) {
                                    if (first_player_field[point_y][j - 1] == ' '
                                       && first_player_field[point_y][j - 2] == ' '
                                       && first_player_field[point_y][j - 3] == ' ') {
                                        for (int i = 0; i < 3; i++) {
                                            first_player_field[point_y][point_x + i] = ' ';
                                            first_player_field[point_y][j - i - 1] = 'O';
                                        }
                                        point_x = j - 3;
                                        j = 0;
                                    }
                                    j--;
                                }

                            }
                        } else if (point_x - 1 != 0 && vertical == true) {
                            if (first_player_field[point_y][point_x - 1] == ' '
                               && first_player_field[point_y + 1][point_x - 1] == ' '
                               && first_player_field[point_y + 2][point_x - 1] == ' ') {
                                for (int i = 0; i < 3; i++) {
                                    first_player_field[point_y + i][point_x - 1] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_x -= 1;
                            }
                         else {
                             int j = point_x - 1;
                                while (j - 1 > 0) {
                                    if (first_player_field[point_y][j] == ' '
                                        && first_player_field[point_y + 1][j] == ' '
                                        && first_player_field[point_y + 2][j] == ' ') {
                                          for (int i = 0; i < 3; i++) {
                                            first_player_field[point_y + i][j] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';
                                        }
                                        point_x = j;
                                        j = 0;
                                    }
                                    j--;
                                }
                            }
                        }

                        break;
                    case 'f':

                        if (gorisontal == true && point_y < HEIGHT - 3
                           && first_player_field[point_y + 1][point_x] == ' '
                           && first_player_field[point_y + 2][point_x] == ' ') {
                            gorisontal = false;
                            vertical = true;
                            for (int i = 0; i < 3; i++) {
                                    first_player_field[point_y + i][point_x] = 'O';
                                    if (i != 2) {
                                        first_player_field[point_y][point_x + i + 1] = ' ';
                                    }
                            }
                        } else if (vertical == true && point_x < WIDTH - 4
                                  && first_player_field[point_y][point_x + 1] == ' '
                                  && first_player_field[point_y][point_x + 2] == ' ') {
                            gorisontal = true;
                            vertical = false;
                            for (int i = 0; i < 3; i++) {
                                first_player_field[point_y][point_x + i] = 'O';
                                if (i != 2) {
                                    first_player_field[point_y + i + 1][point_x] = ' ';
                                }
                            }
                        }

                        break;
                    case 10:

                        if (gorisontal == true) {
                            for (int i = 0; i < 3; i++) {
                                first_player_field[point_y][point_x + i] = '0';
                                if (first_player_field[point_y + 1][point_x] != '#')
                                    first_player_field[point_y + 1][point_x + i] = '+';
                                if (first_player_field[point_y - 1][point_x] != '#')
                                    first_player_field[point_y - 1][point_x + i] = '+';

                                if (first_player_field[point_y][point_x - 1] != '#') {
                                    first_player_field[point_y][point_x - 1] = '+';
                                    if (first_player_field[point_y - 1][point_x - 1] != '#')
                                        first_player_field[point_y - 1][point_x - 1] = '+';
                                    if (first_player_field[point_y + 1][point_x - 1] != '#')
                                        first_player_field[point_y + 1][point_x - 1] = '+';
                                }
                                if (first_player_field[point_y][point_x + 3] != '#') {
                                    first_player_field[point_y][point_x + 3] = '+';
                                    if (first_player_field[point_y - 1][point_x + 3] != '#')
                                        first_player_field[point_y - 1][point_x + 3] = '+';
                                    if (first_player_field[point_y + 1][point_x + 3] != '#')
                                        first_player_field[point_y + 1][point_x + 3] = '+';
                                }
                            }
                        } else {
                            for (int i = 0; i < 3; i++) {
                                first_player_field[point_y + i][point_x] = '0';
                                if (first_player_field[point_y][point_x - 1] != '#')
                                    first_player_field[point_y + i][point_x - 1] = '+';
                                if (first_player_field[point_y][point_x + 1] != '#')
                                    first_player_field[point_y + i][point_x + 1] = '+';

                                if (first_player_field[point_y - 1][point_x] != '#') {
                                    first_player_field[point_y - 1][point_x] = '+';
                                    if (first_player_field[point_y - 1][point_x - 1] != '#')
                                        first_player_field[point_y - 1][point_x - 1] = '+';
                                    if (first_player_field[point_y - 1][point_x + 1] != '#')
                                        first_player_field[point_y - 1][point_x + 1] = '+';
                                }
                                if (first_player_field[point_y + 3][point_x] != '#') {
                                    first_player_field[point_y + 3][point_x] = '+';
                                    if (first_player_field[point_y + 3][point_x - 1] != '#')
                                        first_player_field[point_y + 3][point_x - 1] = '+';
                                    if (first_player_field[point_y + 3][point_x + 1] != '#')
                                        first_player_field[point_y + 3][point_x + 1] = '+';
                                }
                            }
                        }
                        if (ships_3x_num == 1) {
                            ships_3x = false;
                        } else {
                            ships_3x_num -= 1;
                        }
                        break;
                }
            }
            break;
                
        case '3':
            if (ships_2x)
            while (move != 10) {

                    if (gorisontal == true && vertical == false) {
                        if (first_player_field[point_y][point_x] != '0'
                          && first_player_field[point_y][point_x + 1] != '0'
                          && first_player_field[point_y][point_x] != '+'
                          && first_player_field[point_y][point_x + 1] != '+') {
                           for (int i = 0; i < 2; i++) {
                               first_player_field[point_y][point_x + i] = 'O';
                           }
                       } else {
                           while(first_player_field[point_y][point_x] == '+'
                                || first_player_field[point_y][point_x + 1] == '+'
                                || first_player_field[point_y][point_x] == '0'
                                || first_player_field[point_y][point_x + 1] == '0') {
                              point_x++;
                              if (point_x == WIDTH - 3) {
                                  point_y++;
                                  point_x = 1;
                               }
                          }
                          for (int i = 0; i < 2; i++) {
                              first_player_field[point_y][point_x + i] = 'O';
                          }
                       }
                    } else if (vertical == true && gorisontal == false) {
                        for (int i = 0; i < 2; i++) {
                            first_player_field[point_y + i][point_x] = 'O';
                        }
                    }
                    
                

                building_map_first_player();
                move = getch();
                switch (move) {
                    case 's':
                        if (point_y + 2 < HEIGHT && gorisontal == true) {

                                if (first_player_field[point_y + 1][point_x] == ' '
                                   && first_player_field[point_y + 1][point_x + 1] == ' ') {
                                    for (int i = 0; i < 2; i++) {
                                        first_player_field[point_y][point_x + i] = ' ';
                                        first_player_field[point_y + 1][point_x + i] = 'O';
                                    }
                                    point_y += 1;
                                } else {
                                    int j = point_y + 1;
                                    while (j + 2 < HEIGHT) {
                                        if (first_player_field[j + 1][point_x] == ' '
                                           && first_player_field[j + 1][point_x + 1] == ' ') {
                                            for (int i = 0; i < 2; i++) {
                                                first_player_field[point_y][point_x + i] = ' ';
                                                first_player_field[j + 1][point_x + i] = 'O';
                                            }
                                            point_y = j + 1;
                                            j = HEIGHT;
                                        }
                                        j++;
                                    }
                                }
                        } else if (point_y + 3 != HEIGHT && vertical == true) {

                            if (first_player_field[point_y + 2][point_x] == ' ') {
                                for (int i = 0; i < 2; i++) {
                                    first_player_field[point_y + i + 1][point_x] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_y += 1;
                            } else {
                                int j = point_y + 3;
                                while (j + 2 < HEIGHT) {
                                    if (first_player_field[j + 1][point_x] == ' '
                                       && first_player_field[j + 2][point_x] == ' ') {
                                        for (int i = 0; i < 2; i++) {
                                            first_player_field[j + i + 1][point_x] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';
                                        }
                                        point_y = j + 1;
                                        j = HEIGHT;
                                    }
                                    j++;
                                }
                            }
                        }

                        break;
                    case 'w':

                        if (point_y - 1 != 0 && gorisontal == true) {

                                if (first_player_field[point_y - 1][point_x] == ' '
                                   && first_player_field[point_y - 1][point_x + 1] == ' ') {
                                    for (int i = 0; i < 2; i++) {
                                        first_player_field[point_y][point_x + i] = ' ';
                                        first_player_field[point_y - 1][point_x + i] = 'O';
                                    }
                                    point_y -= 1;
                                } else {
                                    int j = point_y - 1;
                                    while (j - 1 > 0) {
                                        if (first_player_field[j - 1][point_x] == ' '
                                           && first_player_field[j - 1][point_x + 1] == ' ') {
                                            for (int i = 0; i < 2; i++) {
                                                first_player_field[point_y][point_x + i] = ' ';
                                                first_player_field[j - 1][point_x + i] = 'O';
                                            }
                                            point_y = j - 1;
                                            j = 0;
                                        }
                                        j--;
                                    }
                                }

                        } else if (point_y - 1 != 0 && vertical == true) {

                            if (first_player_field[point_y - 1][point_x] == ' ') {
                                for (int i = 0; i < 2; i++) {
                                    first_player_field[point_y + i - 1][point_x] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_y -= 1;
                            } else {
                                int j = point_y - 1;
                                while(j - 1 > 0) {
                                    if (first_player_field[j - 1][point_x] == ' '
                                       && first_player_field[j - 2][point_x] == ' ') {
                                        for (int i = 0; i < 2; i++) {
                                            first_player_field[j - i - 1][point_x] = 'O';
                                            first_player_field[point_y + i][point_x] = ' ';
                                        }
                                        point_y = j - 2;
                                        j = 0;
                                    }
                                    j--;
                                }
                            }
                        }

                        break;
                    case 'd':

                        if (point_x + 2 != WIDTH - 2 && gorisontal == true) {

                            if (first_player_field[point_y][point_x + 2] == ' ') {
                                for (int i = 1; i > -1; i--) {
                                    first_player_field[point_y][point_x + i + 1] = 'O';
                                    first_player_field[point_y][point_x + i] = ' ';
                                }
                                point_x += 1;
                            } else {
                                int j = point_x + 2;
                                while (j + 2 < WIDTH) {
                                    if (first_player_field[point_y][j] == ' '
                                        && first_player_field[point_y][j + 1] == ' ') {
                                        for (int i = 1; i > -1; i--) {
                                             first_player_field[point_y][j + i] = 'O';
                                             first_player_field[point_y][point_x + i] = ' ';
                                        }
                                        point_x = j;
                                        j = WIDTH;
                                    }
                                    j++;
                                }
                            }
                        } else if (point_x + 1 != WIDTH - 2 && vertical == true) {

                            if (first_player_field[point_y][point_x + 1] == ' '
                               && first_player_field[point_y + 1][point_x + 1] == ' ') {
                                for (int i = 0; i < 2; i++) {
                                    first_player_field[point_y + i][point_x + 1] = 'O';
                                    first_player_field[point_y + i][point_x] = ' ';
                                }
                                point_x += 1;
                            } else {
                                int j = point_x + 1;
                                while (j + 2 < WIDTH) {
                                    if (first_player_field[point_y][j] == ' '
                                       && first_player_field[point_y + 1][j] == ' ') {
                                        for (int i = 0; i < 2; i++) {
                                            first_player_field[point_y + i][point_x] = ' ';
                                            first_player_field[point_y + i][j] = 'O';
                                        }
                                        point_x = j;
                                        j = WIDTH;
                                    }
                                    j++;
                                }
                            }
                        }

                        break;
                    case 'a':

                        if (point_x - 1 != 0 && gorisontal == true) {
                            if (first_player_field[point_y][point_x - 1] == ' ') {
                                for (int i = 0; i < 2; i++) {
                                    first_player_field[point_y][point_x + i - 1] = 'O';
                                    first_player_field[point_y][point_x + i] = ' ';
                                }
                                point_x -= 1;
                            } else {
                                int j = point_x;
                                while (j - 1 > 0) {
                                    if (first_player_field[point_y][j - 1] == ' '
                                       && first_player_field[point_y][j - 2] == ' ') {
                                         for (int i = 0; i < 2; i++) {
                                             first_player_field[point_y][point_x + i] = ' ';
                                             first_player_field[point_y][j - i - 1] = 'O';
                                         }
                                         point_x = j - 2;
                                         j = 0;
                                     }
                                     j--;
                                 }

                             }
                         } else if (point_x - 1 != 0 && vertical == true) {
                             if (first_player_field[point_y][point_x - 1] == ' '
                                && first_player_field[point_y + 1][point_x - 1] == ' ') {
                                 for (int i = 0; i < 2; i++) {
                                     first_player_field[point_y + i][point_x - 1] = 'O';
                                     first_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_x -= 1;
                             }
                          else {
                              int j = point_x - 1;
                                 while (j - 1 > 0) {
                                     if (first_player_field[point_y][j] == ' '
                                         && first_player_field[point_y + 1][j] == ' ') {
                                           for (int i = 0; i < 2; i++) {
                                             first_player_field[point_y + i][j] = 'O';
                                             first_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_x = j;
                                         j = 0;
                                     }
                                     j--;
                                 }
                             }
                         }

                         break;
                     case 'f':

                         if (gorisontal == true && point_y < HEIGHT - 2
                            && first_player_field[point_y + 1][point_x] == ' ') {
                             gorisontal = false;
                             vertical = true;
                             for (int i = 0; i < 2; i++) {
                                     first_player_field[point_y + i][point_x] = 'O';
                                     if (i != 1) {
                                         first_player_field[point_y][point_x + i + 1] = ' ';
                                     }
                             }
                         } else if (vertical == true && point_x < WIDTH - 3
                                   && first_player_field[point_y][point_x + 1] == ' ') {
                             gorisontal = true;
                             vertical = false;
                             for (int i = 0; i < 2; i++) {
                                 first_player_field[point_y][point_x + i] = 'O';
                                 if (i != 1) {
                                     first_player_field[point_y + i + 1][point_x] = ' ';
                                 }
                             }
                         }

                         break;
                     case 10:

                         if (gorisontal == true) {
                             for (int i = 0; i < 2; i++) {
                                 first_player_field[point_y][point_x + i] = '0';
                                 if (first_player_field[point_y + 1][point_x] != '#')
                                     first_player_field[point_y + 1][point_x + i] = '+';
                                 if (first_player_field[point_y - 1][point_x] != '#')
                                     first_player_field[point_y - 1][point_x + i] = '+';

                                 if (first_player_field[point_y][point_x - 1] != '#') {
                                     first_player_field[point_y][point_x - 1] = '+';
                                     if (first_player_field[point_y - 1][point_x - 1] != '#')
                                         first_player_field[point_y - 1][point_x - 1] = '+';
                                     if (first_player_field[point_y + 1][point_x - 1] != '#')
                                         first_player_field[point_y + 1][point_x - 1] = '+';
                                 }
                                 if (first_player_field[point_y][point_x + 2] != '#') {
                                     first_player_field[point_y][point_x + 2] = '+';
                                     if (first_player_field[point_y - 1][point_x + 2] != '#')
                                         first_player_field[point_y - 1][point_x + 2] = '+';
                                     if (first_player_field[point_y + 1][point_x + 2] != '#')
                                         first_player_field[point_y + 1][point_x + 2] = '+';
                                 }
                             }
                         } else {
                             for (int i = 0; i < 2; i++) {
                                 first_player_field[point_y + i][point_x] = '0';
                                 if (first_player_field[point_y][point_x - 1] != '#')
                                     first_player_field[point_y + i][point_x - 1] = '+';
                                 if (first_player_field[point_y][point_x + 1] != '#')
                                     first_player_field[point_y + i][point_x + 1] = '+';

                                 if (first_player_field[point_y - 1][point_x] != '#') {
                                     first_player_field[point_y - 1][point_x] = '+';
                                     if (first_player_field[point_y - 1][point_x - 1] != '#')
                                         first_player_field[point_y - 1][point_x - 1] = '+';
                                     if (first_player_field[point_y - 1][point_x + 1] != '#')
                                         first_player_field[point_y - 1][point_x + 1] = '+';
                                 }
                                 if (first_player_field[point_y + 2][point_x] != '#') {
                                     first_player_field[point_y + 2][point_x] = '+';
                                     if (first_player_field[point_y + 2][point_x - 1] != '#')
                                         first_player_field[point_y + 2][point_x - 1] = '+';
                                     if (first_player_field[point_y + 2][point_x + 1] != '#')
                                         first_player_field[point_y + 2][point_x + 1] = '+';
                                 }
                             }
                         }
                         if (ships_2x_num == 1) {
                             ships_2x = false;
                         } else {
                             ships_2x_num -= 1;
                         }
                         break;
                 }
             }
             break;


         case '4':
            if (ships_1x)
                 while (move != 10) {
                 if (gorisontal == true && vertical == false && first_player_field[point_y][point_x] != '0'
                     && first_player_field[point_y][point_x] != '+') {
                         first_player_field[point_y][point_x] = 'O';
                 } else {
                     while (first_player_field[point_y][point_x] != ' ') {
                     point_x++;
                        if (point_x == WIDTH - 2) {
                            point_x = 1;
                            point_y++;
                        }
                     }
                     first_player_field[point_y][point_x] = 'O';
                 }
 
                 building_map_first_player();
                 move = getch();
                 switch (move) {
                     case 's':

                         if (point_y + 2 < HEIGHT && gorisontal == true) {
 
                                 if (first_player_field[point_y + 1][point_x] == ' ') {
                                     first_player_field[point_y][point_x] = ' ';
                                     first_player_field[point_y + 1][point_x] = 'O';
                                     point_y += 1;
                                 } else {
                                     int j = point_y + 1;
                                     while (j + 2 < HEIGHT) {
                                         if (first_player_field[j + 1][point_x] == ' ') {
                                             first_player_field[point_y][point_x] = ' ';
                                             first_player_field[j + 1][point_x] = 'O';
                                             point_y = j + 1;
                                             j = HEIGHT;
                                         }
                                         j++;
                                     }
                                 }
                         }

                         break;
                     case 'w':

                         if (point_y - 1 != 0 && gorisontal == true) {

                                 if (first_player_field[point_y - 1][point_x] == ' ') {
                                     first_player_field[point_y][point_x] = ' ';
                                     first_player_field[point_y - 1][point_x] = 'O';
                                     point_y -= 1;
                                 } else {
                                     int j = point_y - 1;
                                     while (j - 1 > 0) {
                                         if (first_player_field[j - 1][point_x] == ' ') {
                                             first_player_field[point_y][point_x] = ' ';
                                             first_player_field[j - 1][point_x] = 'O';
                                             point_y = j - 1;
                                             j = 0;
                                         }
                                         j--;
                                     }
                                 }
                         }

                         break;
                     case 'd':

                         if (point_x + 1 != WIDTH - 2 && gorisontal == true) {

                             if (first_player_field[point_y][point_x + 1] == ' ') {
                                 first_player_field[point_y][point_x + 1] = 'O';
                                 first_player_field[point_y][point_x] = ' ';
                                 point_x += 1;
                             } else {
                                 int j = point_x + 2;
                                 while (j + 2 < WIDTH) {
                                     if (first_player_field[point_y][j] == ' ') {
                                         first_player_field[point_y][j] = 'O';
                                         first_player_field[point_y][point_x] = ' ';
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
                         }

                         break;
                     case 'a':

                         if (point_x - 1 != 0 && gorisontal == true) {
                             if (first_player_field[point_y][point_x - 1] == ' ') {
                                 first_player_field[point_y][point_x - 1] = 'O';
                                 first_player_field[point_y][point_x] = ' ';
                                 point_x -= 1;
                             } else {
                                 int j = point_x;
                                 while (j - 1 > 0) {
                                     if (first_player_field[point_y][j - 1] == ' ') {
                                          first_player_field[point_y][point_x] = ' ';
                                          first_player_field[point_y][j - 1] = 'O';
                                          point_x = j - 1;
                                          j = 0;
                                      }
                                      j--;
                                  }

                              }
                          }

                          break;
                      case 10:
 
                                  first_player_field[point_y][point_x] = '0';
                                  if (first_player_field[point_y + 1][point_x] != '#')
                                      first_player_field[point_y + 1][point_x] = '+';
                                  if (first_player_field[point_y - 1][point_x] != '#')
                                      first_player_field[point_y - 1][point_x] = '+';
 
                                  if (first_player_field[point_y][point_x - 1] != '#') {
                                      first_player_field[point_y][point_x - 1] = '+';
                                      if (first_player_field[point_y - 1][point_x - 1] != '#')
                                          first_player_field[point_y - 1][point_x - 1] = '+';
                                      if (first_player_field[point_y + 1][point_x - 1] != '#')
                                          first_player_field[point_y + 1][point_x - 1] = '+';
                                  }
                                  if (first_player_field[point_y][point_x + 1] != '#') {
                                      first_player_field[point_y][point_x + 1] = '+';
                                      if (first_player_field[point_y - 1][point_x + 1] != '#')
                                          first_player_field[point_y - 1][point_x + 1] = '+';
                                      if (first_player_field[point_y + 1][point_x + 1] != '#')
                                          first_player_field[point_y + 1][point_x + 1] = '+';
                                  }
                              
                          
                          if (ships_1x_num == 1) {
                              ships_1x = false;
                          } else {
                              ships_1x_num -= 1;
                          }
                          break;
                  }
              }
              break;
    } // switch(choise)

    mini_reset();
}

void building_map_first_player () {
    clear();
    attron(COLOR_PAIR(1));
    printw("\t\t\tFirst player\n\n\n");
    for (int i = 0; i < HEIGHT; i++) {
        printw("\t\t     ");
        for (int j = 0; j < WIDTH; j++) {
            if (j == WIDTH - 1) {
                printw("\n");
            } else {
                if (first_player_field[i][j] == 'O')
                    attron(COLOR_PAIR(3));
                if (first_player_field[i][j] == '0')
                    attron(COLOR_PAIR(4));    
                printw("%c", first_player_field[i][j]);
                    attroff(COLOR_PAIR(3));
                    attroff(COLOR_PAIR(4)); 
            }
        }
    }

    printw("\n\n\t\tUse WASD to move your ships");
    printw("\n\t\tPress f to change position");
    printw("\n\t\tPress Enter to put your ships");
}

void mini_reset() {
    point_x = 1;
    point_y = 1;
    gorisontal = true;
    vertical = false;
}

void building_map_second_player () {
     clear();
     attron(COLOR_PAIR(1));
     printw("\t\t\tSecond player\n\n\n");
     for (int i = 0; i < HEIGHT; i++) {
         printw("\t\t     ");
         for (int j = 0; j < WIDTH; j++) {
             if (j == WIDTH - 1) {
                 printw("\n");
             } else {
                 if (second_player_field[i][j] == 'O')
                     attron(COLOR_PAIR(3));
                 if (second_player_field[i][j] == '0')
                     attron(COLOR_PAIR(4));
                 printw("%c", second_player_field[i][j]);
                     attroff(COLOR_PAIR(3));
                     attroff(COLOR_PAIR(4));
             }
         }
     }
 
     printw("\n\n\t\tUse WASD to move your ships");
     printw("\n\t\tPress f to change position");
     printw("\n\t\tPress Enter to put your ships");
}


void map_for_second_player() {

     building_map_second_player();
 
     printw("\n");
     if (ship_4x)
         printw("\n\t\t    Press 1 for 4x Ship");
     if (ships_3x)
         printw("\n\t\t    Press 2 for 3x Ship");
     if (ships_2x)
         printw("\n\t\t    Press 3 for 2x Ship");
     if (ships_1x)
         printw("\n\t\t    Press 4 for 1x Ship");
     if (ship_4x || ships_3x || ships_2x || ships_1x)
         printw("\n\t\t      Your choise - ");
 
     int choise = '-';
     if (choise == '-' && (ship_4x == true || ships_3x == true || ships_2x == true || ships_1x == true)) {
         choise = getch();
     }
 
     int move = '-';
 
     switch (choise) {
         case '1':
             if (ship_4x)
             while (move != 10) {
 
                      if (gorisontal == true && vertical == false) {
                          if (second_player_field[point_y][point_x] != '0'
                             && second_player_field[point_y][point_x + 1] != '0'
                             && second_player_field[point_y][point_x + 2] != '0'
                             && second_player_field[point_y][point_x + 3] != '0'
                             && second_player_field[point_y][point_x] != '+'
                             && second_player_field[point_y][point_x + 1] != '+'
                             && second_player_field[point_y][point_x + 2] != '+'
                             && second_player_field[point_y][point_x + 3] != '+') {
                             for (int i = 0; i < 4; i++) {
                                 second_player_field[point_y][point_x + i] = 'O';
                             }
                          } else {
                             while(second_player_field[point_y][point_x] == '+'
                                   || second_player_field[point_y][point_x + 1] == '+'
                                   || second_player_field[point_y][point_x + 2] == '+'
                                   || second_player_field[point_y][point_x + 3] == '+'
                                   || second_player_field[point_y][point_x] == '0'
                                   || second_player_field[point_y][point_x + 1] == '0'
                                   || second_player_field[point_y][point_x + 2] == '0'
                                   || second_player_field[point_y][point_x + 3] == '0') {
                                 point_x++;
                                 if (point_x == WIDTH - 5) {
                                     point_y++;
                                     point_x = 1;
                                 }
                             }
                             for (int i = 0; i < 4; i++) {
                                 second_player_field[point_y][point_x + i] = 'O';
                             }
 
                          }
                       } else if (vertical == true && gorisontal == false) {
                          for (int i = 0; i < 4; i++) {
                              second_player_field[point_y + i][point_x] = 'O';
                          }
                      }
 
 
                 building_map_second_player();
                 move = getch();
                 switch (move) {
                     case 's':
 
                         if (point_y + 2 < HEIGHT && gorisontal == true) {
 
                                 if (second_player_field[point_y + 1][point_x] == ' '
                                    && second_player_field[point_y + 1][point_x + 1] == ' '
                                    && second_player_field[point_y + 1][point_x + 2] == ' '
                                    && second_player_field[point_y + 1][point_x + 3] == ' ') {
                                     for (int i = 0; i < 4; i++) {
                                         second_player_field[point_y][point_x + i] = ' ';
                                         second_player_field[point_y + 1][point_x + i] = 'O';
                                     }
                                     point_y += 1;
                                 } else {
                                     int j = point_y + 1;
                                     while (j + 2 < HEIGHT) {
                                         if (second_player_field[j + 1][point_x] == ' '
                                            && second_player_field[j + 1][point_x + 1] == ' '
                                            && second_player_field[j + 1][point_x + 2] == ' '
                                            && second_player_field[j + 1][point_x + 3] == ' ') {
                                             for (int i = 0; i < 4; i++) {
                                                 second_player_field[point_y][point_x + i] = ' ';
                                                 second_player_field[j + 1][point_x + i] = 'O';
                                             }
                                             point_y = j + 1;
                                             j = HEIGHT;
                                         }
                                         j++;
                                     }
                                 }
                         } else if (point_y + 5 != HEIGHT && vertical == true) {
 
                             if (second_player_field[point_y + 4][point_x] == ' ') {
                                 for (int i = 0; i < 4; i++) {
                                     second_player_field[point_y + i + 1][point_x] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_y += 1;
                             } else {
                                 int j = point_y + 5;
                                 while (j + 2 < HEIGHT) {
                                     if (second_player_field[j + 1][point_x] == ' '
                                        && second_player_field[j + 2][point_x] == ' '
                                        && second_player_field[j + 3][point_x] == ' '
                                        && second_player_field[j + 4][point_x] == ' ') {
                                         for (int i = 0; i < 4; i++) {
                                             second_player_field[j + i + 1][point_x] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_y = j + 1;
                                         j = HEIGHT;
                                     }
                                     j++;
                                 }
                             }
                         }
 
                         break;
                     case 'w':
 
                          if (point_y - 1 != 0 && gorisontal == true) {
 
                                 if (second_player_field[point_y - 1][point_x] == ' '
                                    && second_player_field[point_y - 1][point_x + 1] == ' '
                                    && second_player_field[point_y - 1][point_x + 2] == ' '
                                    && second_player_field[point_y - 1][point_x + 3] == ' ') {
                                     for (int i = 0; i < 4; i++) {
                                         second_player_field[point_y][point_x + i] = ' ';
                                         second_player_field[point_y - 1][point_x + i] = 'O';
                                     }
                                     point_y -= 1;
                                 } else {
                                     int j = point_y - 1;
                                     while (j - 1 > 0) {
                                         if (second_player_field[j - 1][point_x] == ' '
                                            && second_player_field[j - 1][point_x + 1] == ' '
                                            && second_player_field[j - 1][point_x + 2] == ' '
                                            && second_player_field[j - 1][point_x + 3] == ' ') {
                                             for (int i = 0; i < 4; i++) {
                                                 second_player_field[point_y][point_x + i] = ' ';
                                                 second_player_field[j - 1][point_x + i] = 'O';
                                             }
                                             point_y = j - 1;
                                             j = 0;
                                         }
                                         j--;
                                     }
                                 }
 
                         } else if (point_y - 1 != 0 && vertical == true) {
 
                             if (second_player_field[point_y - 1][point_x] == ' ') {
                                 for (int i = 0; i < 4; i++) {
                                     second_player_field[point_y + i - 1][point_x] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_y -= 1;
                             } else {
                                 int j = point_y - 1;
                                 while(j - 1 > 0) {
                                     if (second_player_field[j - 1][point_x] == ' '
                                        && second_player_field[j - 2][point_x] == ' '
                                        && second_player_field[j - 3][point_x] == ' '
                                        && second_player_field[j - 4][point_x] == ' ') {
                                         for (int i = 0; i < 4; i++) {
                                             second_player_field[j - i - 1][point_x] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_y = j - 4;
                                         j = 0;
                                     }
                                     j--;
                                 }
 
                             }
                         }
 
                         break;
                     case 'd':
 
                         if (point_x + 4 != WIDTH - 2 && gorisontal == true) {
 
                             if (second_player_field[point_y][point_x + 4] == ' ') {
                                 for (int i = 3; i > -1; i--) {
                                     second_player_field[point_y][point_x + i + 1] = 'O';
                                     second_player_field[point_y][point_x + i] = ' ';
                                 }
                                 point_x += 1;
                             } else {
                                 int j = point_x + 4;
                                 while (j + 4 < WIDTH) {
                                     if (second_player_field[point_y][j] == ' '
                                        && second_player_field[point_y][j + 1] == ' '
                                        && second_player_field[point_y][j + 2] == ' '
                                        && second_player_field[point_y][j + 3] == ' ') {
                                         for (int i = 3; i > -1; i--) {
                                              second_player_field[point_y][j + i] = 'O';
                                              second_player_field[point_y][point_x + i] = ' ';
                                         }
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
                         } else if (point_x + 1 != WIDTH - 2 && vertical == true) {
 
                             if (second_player_field[point_y][point_x + 1] == ' '
                                && second_player_field[point_y + 1][point_x + 1] == ' '
                                && second_player_field[point_y + 2][point_x + 1] == ' '
                                && second_player_field[point_y + 3][point_x + 1] == ' ') {
                                 for (int i = 0; i < 4; i++) {
                                     second_player_field[point_y + i][point_x + 1] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_x += 1;
                             } else {
                                 int j = point_x + 1;
                                 while (j + 2 < WIDTH) {
                                     if (second_player_field[point_y][j] == ' '
                                        && second_player_field[point_y + 1][j] == ' '
                                        && second_player_field[point_y + 2][j] == ' '
                                        && second_player_field[point_y + 3][j] == ' ') {
                                         for (int i = 0; i < 4; i++) {
                                             second_player_field[point_y + i][point_x] = ' ';
                                             second_player_field[point_y + i][j] = 'O';
                                         }
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
 
                         }
 
                         break;
                     case 'a':
 
                         if (point_x - 1 != 0 && gorisontal == true) {
                             if (second_player_field[point_y][point_x - 1] == ' ') {
                                 for (int i = 0; i < 4; i++) {
                                     second_player_field[point_y][point_x + i - 1] = 'O';
                                     second_player_field[point_y][point_x + i] = ' ';
                                 }
                                 point_x -= 1;
                             } else {
                                 int j = point_x;
                                 while (j - 1 > 0) {
                                     if (second_player_field[point_y][j - 1] == ' '
                                        && second_player_field[point_y][j - 2] == ' '
                                        && second_player_field[point_y][j - 3] == ' '
                                        && second_player_field[point_y][j - 4] == ' ') {
                                         for (int i = 0; i < 4; i++) {
                                             second_player_field[point_y][point_x + i] = ' ';
                                             second_player_field[point_y][j - i - 1] = 'O';
                                         }
                                         point_x = j - 4;
                                         j = 0;
                                     }
 
                                     j--;
                                 }
 
                             }
                         } else if (point_x - 1 != 0 && vertical == true) {
                             if (second_player_field[point_y][point_x - 1] == ' '
                                && second_player_field[point_y + 1][point_x - 1] == ' '
                                && second_player_field[point_y + 2][point_x - 1] == ' '
                                && second_player_field[point_y + 3][point_x - 1] == ' ') {
                                 for (int i = 0; i < 4; i++) {
                                     second_player_field[point_y + i][point_x - 1] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_x -= 1;
                             }
                          else {
                                 int j = point_x - 1;
                                 while (j - 1 > 0) {
                                     if (second_player_field[point_y][j] == ' '
                                         && second_player_field[point_y + 1][j] == ' '
                                         && second_player_field[point_y + 2][j] == ' '
                                         && second_player_field[point_y + 3][j] == ' ') {
                                           for (int i = 0; i < 4; i++) {
                                             second_player_field[point_y + i][j] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_x = j;
                                         j = 0;
                                     }
                                     j--;
                                 }
                             }
                         }
 
                         break;
                     case 'f':
 
                         if (gorisontal == true && point_y < HEIGHT - 4
                            && second_player_field[point_y + 1][point_x] == ' '
                            && second_player_field[point_y + 2][point_x] == ' '
                            && second_player_field[point_y + 3][point_x] == ' ') {
                             gorisontal = false;
                             vertical = true;
                             for (int i = 0; i < 4; i++) {
                                     second_player_field[point_y + i][point_x] = 'O';
                                     if (i != 3) {
                                         second_player_field[point_y][point_x + i + 1] = ' ';
                                     }
                             }
                         } else if (vertical == true && point_x < WIDTH - 5
                                   && second_player_field[point_y][point_x + 1] == ' '
                                   && second_player_field[point_y][point_x + 2] == ' '
                                   && second_player_field[point_y][point_x + 3] == ' ') {
                             gorisontal = true;
                             vertical = false;
                             for (int i = 0; i < 4; i++) {
                                 second_player_field[point_y][point_x + i] = 'O';
                                 if (i != 3) {
                                     second_player_field[point_y + i + 1][point_x] = ' ';
                                 }
                             }
                         }
 
                         break;
                     case 10:
 
                         if (gorisontal == true) {
                             for (int i = 0; i < 4; i++) {
                                 second_player_field[point_y][point_x + i] = '0';
                                 if (second_player_field[point_y + 1][point_x] != '#')
                                     second_player_field[point_y + 1][point_x + i] = '+';
                                 if (second_player_field[point_y - 1][point_x] != '#')
                                     second_player_field[point_y - 1][point_x + i] = '+';
 
                                 if (second_player_field[point_y][point_x - 1] != '#') {
                                     second_player_field[point_y][point_x - 1] = '+';
                                     if (second_player_field[point_y - 1][point_x - 1] != '#')
                                         second_player_field[point_y - 1][point_x - 1] = '+';
                                     if (second_player_field[point_y + 1][point_x - 1] != '#')
                                         second_player_field[point_y + 1][point_x - 1] = '+';
                                 }
                                 if (second_player_field[point_y][point_x + 4] != '#') {
                                     second_player_field[point_y][point_x + 4] = '+';
                                     if (second_player_field[point_y - 1][point_x + 4] != '#')
                                         second_player_field[point_y - 1][point_x + 4] = '+';
                                     if (second_player_field[point_y + 1][point_x + 4] != '#')
                                         second_player_field[point_y + 1][point_x + 4] = '+';
                                 }
 
                             }
                         } else {
                             for (int i = 0; i < 4; i++) {
                                 second_player_field[point_y + i][point_x] = '0';
                                 if (second_player_field[point_y][point_x - 1] != '#')
                                     second_player_field[point_y + i][point_x - 1] = '+';
                                 if (second_player_field[point_y][point_x + 1] != '#')
                                     second_player_field[point_y + i][point_x + 1] = '+';
 
                                 if (second_player_field[point_y - 1][point_x] != '#') {
                                     second_player_field[point_y - 1][point_x] = '+';
                                     if (second_player_field[point_y - 1][point_x - 1] != '#')
                                         second_player_field[point_y - 1][point_x - 1] = '+';
                                     if (second_player_field[point_y - 1][point_x + 1] != '#')
                                         second_player_field[point_y - 1][point_x + 1] = '+';
                                 }
                                 if (second_player_field[point_y + 4][point_x] != '#') {
                                     second_player_field[point_y + 4][point_x] = '+';
                                     if (second_player_field[point_y + 4][point_x - 1] != '#')
                                         second_player_field[point_y + 4][point_x - 1] = '+';
                                     if (second_player_field[point_y + 4][point_x + 1] != '#')
                                         second_player_field[point_y + 4][point_x + 1] = '+';
                                 }
                             }
                         }
                         ship_4x = false;
 
                         break;
                 }
             }
             break;
 
 
         case '2':
 
             if (ships_3x)
             while (move != 10) {
 
 
                     if (gorisontal == true && vertical == false) {
                         if (second_player_field[point_y][point_x] != '0'
                            && second_player_field[point_y][point_x + 1] != '0'
                            && second_player_field[point_y][point_x + 2] != '0'
                            && second_player_field[point_y][point_x] != '+'
                            && second_player_field[point_y][point_x + 1] != '+'
                            && second_player_field[point_y][point_x + 2] != '+') {
                             for (int i = 0; i < 3; i++) {
                                 second_player_field[point_y][point_x + i] = 'O';
                             }
                         } else {
                             while(second_player_field[point_y][point_x] == '+'
                                  || second_player_field[point_y][point_x + 1] == '+'
                                  || second_player_field[point_y][point_x + 2] == '+'
                                  || second_player_field[point_y][point_x] == '0'
                                  || second_player_field[point_y][point_x + 1] == '0'
                                  || second_player_field[point_y][point_x + 2] == '0') {
                                point_x++;
                                if (point_x == WIDTH - 4) {
                                    point_y++;
                                    point_x = 1;
                                }
                            }
                            for (int i = 0; i < 3; i++) {
                                second_player_field[point_y][point_x + i] = 'O';
                            }
                         }
                      } else if (vertical == true && gorisontal == false) {
                         for (int i = 0; i < 3; i++) {
                             second_player_field[point_y + i][point_x] = 'O';
                         }
                     }
 
 
                 building_map_second_player();
                 move = getch();
                 switch (move) {
                     case 's':
 
                         if (point_y + 2 < HEIGHT && gorisontal == true) {
 
                                 if (second_player_field[point_y + 1][point_x] == ' '
                                    && second_player_field[point_y + 1][point_x + 1] == ' '
                                    && second_player_field[point_y + 1][point_x + 2] == ' ') {
                                     for (int i = 0; i < 3; i++) {
                                         second_player_field[point_y][point_x + i] = ' ';
                                         second_player_field[point_y + 1][point_x + i] = 'O';
                                     }
                                     point_y += 1;
                                 } else {
                                     int j = point_y + 1;
                                     while (j + 2 < HEIGHT) {
                                         if (second_player_field[j + 1][point_x] == ' '
                                            && second_player_field[j + 1][point_x + 1] == ' '
                                            && second_player_field[j + 1][point_x + 2] == ' ') {
                                             for (int i = 0; i < 3; i++) {
                                                 second_player_field[point_y][point_x + i] = ' ';
                                                 second_player_field[j + 1][point_x + i] = 'O';
                                             }
                                             point_y = j + 1;
                                             j = HEIGHT;
                                         }
                                         j++;
                                     }
                                 }
                         } else if (point_y + 4 != HEIGHT && vertical == true) {
 
                             if (second_player_field[point_y + 3][point_x] == ' ') {
                                 for (int i = 0; i < 3; i++) {
                                     second_player_field[point_y + i + 1][point_x] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_y += 1;
                             } else {
                                 int j = point_y + 4;
                                 while (j + 2 < HEIGHT) {
                                     if (second_player_field[j + 1][point_x] == ' '
                                        && second_player_field[j + 2][point_x] == ' '
                                        && second_player_field[j + 3][point_x] == ' ') {
                                         for (int i = 0; i < 3; i++) {
                                             second_player_field[j + i + 1][point_x] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_y = j + 1;
                                         j = HEIGHT;
                                     }
                                     j++;
                                 }
                             }
                         }
 
                         break;
                     case 'w':
 
                         if (point_y - 1 != 0 && gorisontal == true) {
 
                                 if (second_player_field[point_y - 1][point_x] == ' '
                                    && second_player_field[point_y - 1][point_x + 1] == ' '
                                    && second_player_field[point_y - 1][point_x + 2] == ' ') {
                                     for (int i = 0; i < 3; i++) {
                                         second_player_field[point_y][point_x + i] = ' ';
                                         second_player_field[point_y - 1][point_x + i] = 'O';
                                     }
                                     point_y -= 1;
                                 } else {
                                     int j = point_y - 1;
                                     while (j - 1 > 0) {
                                         if (second_player_field[j - 1][point_x] == ' '
                                            && second_player_field[j - 1][point_x + 1] == ' '
                                            && second_player_field[j - 1][point_x + 2] == ' ') {
                                             for (int i = 0; i < 3; i++) {
                                                 second_player_field[point_y][point_x + i] = ' ';
                                                 second_player_field[j - 1][point_x + i] = 'O';
                                             }
                                             point_y = j - 1;
                                             j = 0;
                                         }
                                         j--;
                                     }
                                 }
 
                         } else if (point_y - 1 != 0 && vertical == true) {
 
                             if (second_player_field[point_y - 1][point_x] == ' ') {
                                 for (int i = 0; i < 3; i++) {
                                     second_player_field[point_y + i - 1][point_x] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_y -= 1;
                             } else {
                                 int j = point_y - 1;
                                 while(j - 1 > 0) {
                                     if (second_player_field[j - 1][point_x] == ' '
                                        && second_player_field[j - 2][point_x] == ' '
                                        && second_player_field[j - 3][point_x] == ' ') {
                                         for (int i = 0; i < 3; i++) {
                                             second_player_field[j - i - 1][point_x] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_y = j - 3;
                                         j = 0;
                                     }
                                     j--;
                                 }
                             }
                         }
 
                         break;
                     case 'd':
 
                         if (point_x + 3 != WIDTH - 2 && gorisontal == true) {
 
                              if (second_player_field[point_y][point_x + 3] == ' ') {
                                 for (int i = 2; i > -1; i--) {
                                     second_player_field[point_y][point_x + i + 1] = 'O';
                                     second_player_field[point_y][point_x + i] = ' ';
                                 }
                                 point_x += 1;
                             } else {
                                 int j = point_x + 3;
                                 while (j + 3 < WIDTH) {
                                     if (second_player_field[point_y][j] == ' '
                                        && second_player_field[point_y][j + 1] == ' '
                                        && second_player_field[point_y][j + 2] == ' ') {
                                         for (int i = 2; i > -1; i--) {
                                              second_player_field[point_y][j + i] = 'O';
                                              second_player_field[point_y][point_x + i] = ' ';
                                         }
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
                         } else if (point_x + 1 != WIDTH - 2 && vertical == true) {
 
                             if (second_player_field[point_y][point_x + 1] == ' '
                                && second_player_field[point_y + 1][point_x + 1] == ' '
                                && second_player_field[point_y + 2][point_x + 1] == ' ') {
                                 for (int i = 0; i < 3; i++) {
                                     second_player_field[point_y + i][point_x + 1] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_x += 1;
                             } else {
                                 int j = point_x + 1;
                                 while (j + 2 < WIDTH) {
                                     if (second_player_field[point_y][j] == ' '
                                        && second_player_field[point_y + 1][j] == ' '
                                        && second_player_field[point_y + 2][j] == ' ') {
                                         for (int i = 0; i < 3; i++) {
                                             second_player_field[point_y + i][point_x] = ' ';
                                             second_player_field[point_y + i][j] = 'O';
                                         }
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
                         }
 
                         break;
                     case 'a':
 
                         if (point_x - 1 != 0 && gorisontal == true) {
                             if (second_player_field[point_y][point_x - 1] == ' ') {
                                 for (int i = 0; i < 3; i++) {
                                     second_player_field[point_y][point_x + i - 1] = 'O';
                                     second_player_field[point_y][point_x + i] = ' ';
                                 }
                                 point_x -= 1;
                             } else {
                                 int j = point_x;
                                 while (j - 1 > 0) {
                                     if (second_player_field[point_y][j - 1] == ' '
                                        && second_player_field[point_y][j - 2] == ' '
                                        && second_player_field[point_y][j - 3] == ' ') {
                                         for (int i = 0; i < 3; i++) {
                                             second_player_field[point_y][point_x + i] = ' ';
                                             second_player_field[point_y][j - i - 1] = 'O';
                                         }
                                         point_x = j - 3;
                                         j = 0;
                                     }
                                     j--;
                                 }
 
                             }
                         } else if (point_x - 1 != 0 && vertical == true) {
                             if (second_player_field[point_y][point_x - 1] == ' '
                                && second_player_field[point_y + 1][point_x - 1] == ' '
                                && second_player_field[point_y + 2][point_x - 1] == ' ') {
                                 for (int i = 0; i < 3; i++) {
                                     second_player_field[point_y + i][point_x - 1] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_x -= 1;
                             }
                          else {
                              int j = point_x - 1;
                                 while (j - 1 > 0) {
                                     if (second_player_field[point_y][j] == ' '
                                         && second_player_field[point_y + 1][j] == ' '
                                         && second_player_field[point_y + 2][j] == ' ') {
                                         for (int i = 0; i < 3; i++) {
                                             second_player_field[point_y + i][j] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_x = j;
                                         j = 0;
                                     }
                                     j--;
                                 }
                             }
                         }
 
                         break;
                     case 'f':
 
                         if (gorisontal == true && point_y < HEIGHT - 3
                            && second_player_field[point_y + 1][point_x] == ' '
                            && second_player_field[point_y + 2][point_x] == ' ') {
                             gorisontal = false;
                             vertical = true;
                             for (int i = 0; i < 3; i++) {
                                     second_player_field[point_y + i][point_x] = 'O';
                                     if (i != 2) {
                                         second_player_field[point_y][point_x + i + 1] = ' ';
                                     }
                             }
                         } else if (vertical == true && point_x < WIDTH - 4
                                   && second_player_field[point_y][point_x + 1] == ' '
                                   && second_player_field[point_y][point_x + 2] == ' ') {
                             gorisontal = true;
                             vertical = false;
                             for (int i = 0; i < 3; i++) {
                                 second_player_field[point_y][point_x + i] = 'O';
                                 if (i != 2) {
                                     second_player_field[point_y + i + 1][point_x] = ' ';
                                 }
                             }
                         }
 
                         break;
                     case 10:
 
                         if (gorisontal == true) {
                             for (int i = 0; i < 3; i++) {
                                 second_player_field[point_y][point_x + i] = '0';
                                 if (second_player_field[point_y + 1][point_x] != '#')
                                     second_player_field[point_y + 1][point_x + i] = '+';
                                 if (second_player_field[point_y - 1][point_x] != '#')
                                     second_player_field[point_y - 1][point_x + i] = '+';
 
                                 if (second_player_field[point_y][point_x - 1] != '#') {
                                     second_player_field[point_y][point_x - 1] = '+';
                                     if (second_player_field[point_y - 1][point_x - 1] != '#')
                                         second_player_field[point_y - 1][point_x - 1] = '+';
                                     if (second_player_field[point_y + 1][point_x - 1] != '#')
                                         second_player_field[point_y + 1][point_x - 1] = '+';
                                 }
                                 if (second_player_field[point_y][point_x + 3] != '#') {
                                     second_player_field[point_y][point_x + 3] = '+';
                                     if (second_player_field[point_y - 1][point_x + 3] != '#')
                                         second_player_field[point_y - 1][point_x + 3] = '+';
                                     if (second_player_field[point_y + 1][point_x + 3] != '#')
                                         second_player_field[point_y + 1][point_x + 3] = '+';
                                 }
                             }
                         } else {
                             for (int i = 0; i < 3; i++) {
                                 second_player_field[point_y + i][point_x] = '0';
                                 if (second_player_field[point_y][point_x - 1] != '#')
                                     second_player_field[point_y + i][point_x - 1] = '+';
                                 if (second_player_field[point_y][point_x + 1] != '#')
                                     second_player_field[point_y + i][point_x + 1] = '+';
 
                                 if (second_player_field[point_y - 1][point_x] != '#') {
                                     second_player_field[point_y - 1][point_x] = '+';
                                     if (second_player_field[point_y - 1][point_x - 1] != '#')
                                         second_player_field[point_y - 1][point_x - 1] = '+';
                                     if (second_player_field[point_y - 1][point_x + 1] != '#')
                                         second_player_field[point_y - 1][point_x + 1] = '+';
                                 }
                                 if (second_player_field[point_y + 3][point_x] != '#') {
                                     second_player_field[point_y + 3][point_x] = '+';
                                     if (second_player_field[point_y + 3][point_x - 1] != '#')
                                         second_player_field[point_y + 3][point_x - 1] = '+';
                                     if (second_player_field[point_y + 3][point_x + 1] != '#')
                                         second_player_field[point_y + 3][point_x + 1] = '+';
                                 }
                             }
                         }
                         if (ships_3x_num == 1) {
                             ships_3x = false;
                         } else {
                             ships_3x_num -= 1;
                         }
                         break;
                 }
             }
             break;
 
         case '3':
             if (ships_2x)
             while (move != 10) {
 
                     if (gorisontal == true && vertical == false) {
                         if (second_player_field[point_y][point_x] != '0'
                           && second_player_field[point_y][point_x + 1] != '0'
                           && second_player_field[point_y][point_x] != '+'
                           && second_player_field[point_y][point_x + 1] != '+') {
                            for (int i = 0; i < 2; i++) {
                                second_player_field[point_y][point_x + i] = 'O';
                            }
                        } else {
                            while(second_player_field[point_y][point_x] == '+'
                                 || second_player_field[point_y][point_x + 1] == '+'
                                 || second_player_field[point_y][point_x] == '0'
                                 || second_player_field[point_y][point_x + 1] == '0') {
                               point_x++;
                               if (point_x == WIDTH - 3) {
                                   point_y++;
                                   point_x = 1;
                                }
                           }
                           for (int i = 0; i < 2; i++) {
                               second_player_field[point_y][point_x + i] = 'O';
                           }
                        }
                     } else if (vertical == true && gorisontal == false) {
                         for (int i = 0; i < 2; i++) {
                             second_player_field[point_y + i][point_x] = 'O';
                         }
                     }

 
 
                 building_map_second_player();
                 move = getch();
                 switch (move) {
                     case 's':
                         if (point_y + 2 < HEIGHT && gorisontal == true) {
 
                                 if (second_player_field[point_y + 1][point_x] == ' '
                                    && second_player_field[point_y + 1][point_x + 1] == ' ') {
                                     for (int i = 0; i < 2; i++) {
                                         second_player_field[point_y][point_x + i] = ' ';
                                         second_player_field[point_y + 1][point_x + i] = 'O';
                                     }
                                     point_y += 1;
                                 } else {
                                     int j = point_y + 1;
                                     while (j + 2 < HEIGHT) {
                                         if (second_player_field[j + 1][point_x] == ' '
                                            && second_player_field[j + 1][point_x + 1] == ' ') {
                                             for (int i = 0; i < 2; i++) {
                                                 second_player_field[point_y][point_x + i] = ' ';
                                                 second_player_field[j + 1][point_x + i] = 'O';
                                             }
                                             point_y = j + 1;
                                             j = HEIGHT;
                                         }
                                         j++;
                                     }
                                 }
                         } else if (point_y + 3 != HEIGHT && vertical == true) {
 
                             if (second_player_field[point_y + 2][point_x] == ' ') {
                                 for (int i = 0; i < 2; i++) {
                                     second_player_field[point_y + i + 1][point_x] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_y += 1;
                             } else {
                                 int j = point_y + 3;
                                 while (j + 2 < HEIGHT) {
                                     if (second_player_field[j + 1][point_x] == ' '
                                        && second_player_field[j + 2][point_x] == ' ') {
                                         for (int i = 0; i < 2; i++) {
                                             second_player_field[j + i + 1][point_x] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_y = j + 1;
                                         j = HEIGHT;
                                     }
                                     j++;
                                 }
                             }
                         }
 
                         break;
                     case 'w':
 
                         if (point_y - 1 != 0 && gorisontal == true) {
 
                                 if (second_player_field[point_y - 1][point_x] == ' '
                                    && second_player_field[point_y - 1][point_x + 1] == ' ') {
                                     for (int i = 0; i < 2; i++) {
                                         second_player_field[point_y][point_x + i] = ' ';
                                         second_player_field[point_y - 1][point_x + i] = 'O';
                                     }
                                     point_y -= 1;
                                 } else {
                                     int j = point_y - 1;
                                     while (j - 1 > 0) {
                                         if (second_player_field[j - 1][point_x] == ' '
                                            && second_player_field[j - 1][point_x + 1] == ' ') {
                                             for (int i = 0; i < 2; i++) {
                                                 second_player_field[point_y][point_x + i] = ' ';
                                                 second_player_field[j - 1][point_x + i] = 'O';
                                             } 
                                             point_y = j - 1;
                                             j = 0;
                                         }
                                         j--;
                                     }
                                 }
 
                         } else if (point_y - 1 != 0 && vertical == true) {
 
                             if (second_player_field[point_y - 1][point_x] == ' ') {
                                 for (int i = 0; i < 2; i++) {
                                     second_player_field[point_y + i - 1][point_x] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_y -= 1;
                             } else {
                                 int j = point_y - 1;
                                 while(j - 1 > 0) {
                                     if (second_player_field[j - 1][point_x] == ' '
                                        && second_player_field[j - 2][point_x] == ' ') {
                                         for (int i = 0; i < 2; i++) {
                                             second_player_field[j - i - 1][point_x] = 'O';
                                             second_player_field[point_y + i][point_x] = ' ';
                                         }
                                         point_y = j - 2;
                                         j = 0;
                                     }
                                     j--;
                                 }
                             }
                         }
 
                         break;
                     case 'd':
 
                         if (point_x + 2 != WIDTH - 2 && gorisontal == true) {
 
                             if (second_player_field[point_y][point_x + 2] == ' ') {
                                 for (int i = 1; i > -1; i--) {
                                     second_player_field[point_y][point_x + i + 1] = 'O';
                                     second_player_field[point_y][point_x + i] = ' ';
                                 }
                                 point_x += 1;
                             } else {
                                 int j = point_x + 2;
                                 while (j + 2 < WIDTH) {
                                     if (second_player_field[point_y][j] == ' '
                                         && second_player_field[point_y][j + 1] == ' ') {
                                         for (int i = 1; i > -1; i--) {
                                              second_player_field[point_y][j + i] = 'O';
                                              second_player_field[point_y][point_x + i] = ' ';
                                         }
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
                         } else if (point_x + 1 != WIDTH - 2 && vertical == true) {
 
                             if (second_player_field[point_y][point_x + 1] == ' '
                                && second_player_field[point_y + 1][point_x + 1] == ' ') {
                                 for (int i = 0; i < 2; i++) {
                                     second_player_field[point_y + i][point_x + 1] = 'O';
                                     second_player_field[point_y + i][point_x] = ' ';
                                 }
                                 point_x += 1;
                             } else {
                                 int j = point_x + 1;
                                 while (j + 2 < WIDTH) {
                                     if (second_player_field[point_y][j] == ' '
                                        && second_player_field[point_y + 1][j] == ' ') {
                                         for (int i = 0; i < 2; i++) {
                                             second_player_field[point_y + i][point_x] = ' ';
                                             second_player_field[point_y + i][j] = 'O';
                                         }
                                         point_x = j;
                                         j = WIDTH;
                                     }
                                     j++;
                                 }
                             }
                         }
 
                         break;
                     case 'a':
 
                         if (point_x - 1 != 0 && gorisontal == true) {
                             if (second_player_field[point_y][point_x - 1] == ' ') {
                                 for (int i = 0; i < 2; i++) {
                                     second_player_field[point_y][point_x + i - 1] = 'O';
                                     second_player_field[point_y][point_x + i] = ' ';
                                 }
                                 point_x -= 1;
                             } else {
                                 int j = point_x;
                                 while (j - 1 > 0) {
                                     if (second_player_field[point_y][j - 1] == ' '
                                        && second_player_field[point_y][j - 2] == ' ') {
                                          for (int i = 0; i < 2; i++) {
                                              second_player_field[point_y][point_x + i] = ' ';
                                              second_player_field[point_y][j - i - 1] = 'O';
                                          }
                                          point_x = j - 2;
                                          j = 0;
                                      }
                                      j--;
                                  }
 
                              }
                          } else if (point_x - 1 != 0 && vertical == true) {
                              if (second_player_field[point_y][point_x - 1] == ' '
                                 && second_player_field[point_y + 1][point_x - 1] == ' ') {
                                  for (int i = 0; i < 2; i++) {
                                      second_player_field[point_y + i][point_x - 1] = 'O';
                                      second_player_field[point_y + i][point_x] = ' ';
                                  }
                                  point_x -= 1;
                              }
                           else {
                               int j = point_x - 1;
                                  while (j - 1 > 0) {
                                      if (second_player_field[point_y][j] == ' '
                                          && second_player_field[point_y + 1][j] == ' ') {
                                            for (int i = 0; i < 2; i++) {
                                              second_player_field[point_y + i][j] = 'O';
                                              second_player_field[point_y + i][point_x] = ' ';
                                          }
                                          point_x = j;
                                          j = 0;
                                      }
                                      j--;
                                  }
                              }
                          }
 
                          break;
                      case 'f':
 
                          if (gorisontal == true && point_y < HEIGHT - 2
                             && second_player_field[point_y + 1][point_x] == ' ') {
                              gorisontal = false;
                              vertical = true;
                              for (int i = 0; i < 2; i++) {
                                      second_player_field[point_y + i][point_x] = 'O';
                                      if (i != 1) {
                                          second_player_field[point_y][point_x + i + 1] = ' ';
                                      }
                              }
                          } else if (vertical == true && point_x < WIDTH - 3
                                    && second_player_field[point_y][point_x + 1] == ' ') {
                              gorisontal = true;
                              vertical = false;
                              for (int i = 0; i < 2; i++) {
                                  second_player_field[point_y][point_x + i] = 'O';
                                  if (i != 1) {
                                      second_player_field[point_y + i + 1][point_x] = ' ';
                                  }
                              }
                          }
 
                          break;
                      case 10:
 
                          if (gorisontal == true) {
                              for (int i = 0; i < 2; i++) {
                                  second_player_field[point_y][point_x + i] = '0';
                                  if (second_player_field[point_y + 1][point_x] != '#')
                                      second_player_field[point_y + 1][point_x + i] = '+';
                                  if (second_player_field[point_y - 1][point_x] != '#')
                                      second_player_field[point_y - 1][point_x + i] = '+';
 
                                  if (second_player_field[point_y][point_x - 1] != '#') {
                                      second_player_field[point_y][point_x - 1] = '+';
                                      if (second_player_field[point_y - 1][point_x - 1] != '#')
                                          second_player_field[point_y - 1][point_x - 1] = '+';
                                      if (second_player_field[point_y + 1][point_x - 1] != '#')
                                          second_player_field[point_y + 1][point_x - 1] = '+';
                                  }
                                  if (second_player_field[point_y][point_x + 2] != '#') {
                                      second_player_field[point_y][point_x + 2] = '+';
                                      if (second_player_field[point_y - 1][point_x + 2] != '#')
                                          second_player_field[point_y - 1][point_x + 2] = '+';
                                      if (second_player_field[point_y + 1][point_x + 2] != '#')
                                          second_player_field[point_y + 1][point_x + 2] = '+';
                                  }
                              }
                          } else {
                              for (int i = 0; i < 2; i++) {
                                  second_player_field[point_y + i][point_x] = '0';
                                  if (second_player_field[point_y][point_x - 1] != '#')
                                      second_player_field[point_y + i][point_x - 1] = '+';
                                  if (second_player_field[point_y][point_x + 1] != '#')
                                      second_player_field[point_y + i][point_x + 1] = '+';
 
                                  if (second_player_field[point_y - 1][point_x] != '#') {
                                      second_player_field[point_y - 1][point_x] = '+';
                                      if (second_player_field[point_y - 1][point_x - 1] != '#')
                                          second_player_field[point_y - 1][point_x - 1] = '+';
                                      if (second_player_field[point_y - 1][point_x + 1] != '#')
                                          second_player_field[point_y - 1][point_x + 1] = '+';
                                  }
                                  if (second_player_field[point_y + 2][point_x] != '#') {
                                      second_player_field[point_y + 2][point_x] = '+';
                                      if (second_player_field[point_y + 2][point_x - 1] != '#')
                                          second_player_field[point_y + 2][point_x - 1] = '+';
                                      if (second_player_field[point_y + 2][point_x + 1] != '#')
                                          second_player_field[point_y + 2][point_x + 1] = '+';
                                  }
                              }
                          }
                          if (ships_2x_num == 1) {
                              ships_2x = false;
                          } else {
                              ships_2x_num -= 1;
                          }
                          break;
                  }
              }
              break;
 
 
          case '4':
             if (ships_1x)
                  while (move != 10) {
                  if (gorisontal == true && vertical == false && second_player_field[point_y][point_x] != '0'
                      && second_player_field[point_y][point_x] != '+') {
                          second_player_field[point_y][point_x] = 'O';
                  } else {
                      while (second_player_field[point_y][point_x] != ' ') {
                      point_x++;
                         if (point_x == WIDTH - 2) {
                             point_x = 1;
                             point_y++;
                         }
                      }
                      second_player_field[point_y][point_x] = 'O';
                  }
 
                  building_map_second_player();
                  move = getch();
                  switch (move) {
                      case 's':
 
                          if (point_y + 2 < HEIGHT && gorisontal == true) {
 
                                  if (second_player_field[point_y + 1][point_x] == ' ') {
                                      second_player_field[point_y][point_x] = ' ';
                                      second_player_field[point_y + 1][point_x] = 'O';
                                      point_y += 1;
                                  } else {
                                      int j = point_y + 1;
                                      while (j + 2 < HEIGHT) {
                                          if (second_player_field[j + 1][point_x] == ' ') {
                                              second_player_field[point_y][point_x] = ' ';
                                              second_player_field[j + 1][point_x] = 'O';
                                              point_y = j + 1;
                                              j = HEIGHT;
                                          }
                                          j++;
                                      }
                                  }
                          }
 
                          break;
                      case 'w':
 
                          if (point_y - 1 != 0 && gorisontal == true) {
                                   if (second_player_field[point_y - 1][point_x] == ' ') {
                                      second_player_field[point_y][point_x] = ' ';
                                      second_player_field[point_y - 1][point_x] = 'O';
                                      point_y -= 1;
                                  } else {
                                      int j = point_y - 1;
                                      while (j - 1 > 0) {
                                          if (second_player_field[j - 1][point_x] == ' ') {
                                              second_player_field[point_y][point_x] = ' ';
                                              second_player_field[j - 1][point_x] = 'O';
                                              point_y = j - 1;
                                              j = 0;
                                          }
                                          j--;
                                      }
                                  }
                          }
 
                          break;
                      case 'd':
 
                          if (point_x + 1 != WIDTH - 2 && gorisontal == true) {
 
                              if (second_player_field[point_y][point_x + 1] == ' ') {
                                  second_player_field[point_y][point_x + 1] = 'O';
                                  second_player_field[point_y][point_x] = ' ';
                                  point_x += 1;
                              } else {
                                  int j = point_x + 2;
                                  while (j + 2 < WIDTH) {
                                      if (second_player_field[point_y][j] == ' ') {
                                          second_player_field[point_y][j] = 'O';
                                          second_player_field[point_y][point_x] = ' ';
                                          point_x = j;
                                          j = WIDTH;
                                      }
                                      j++;
                                  }
                              }
                          }
 
                          break;
                      case 'a':
 
                          if (point_x - 1 != 0 && gorisontal == true) {
                              if (second_player_field[point_y][point_x - 1] == ' ') {
                                  second_player_field[point_y][point_x - 1] = 'O';
                                  second_player_field[point_y][point_x] = ' ';
                                  point_x -= 1;
                              } else {
                                  int j = point_x;
                                  while (j - 1 > 0) {
                                      if (second_player_field[point_y][j - 1] == ' ') {
                                           second_player_field[point_y][point_x] = ' ';
                                           second_player_field[point_y][j - 1] = 'O';
                                           point_x = j - 1;
                                           j = 0;
                                       }
                                       j--;
                                   }
 
                               }
                           }
 
                           break;
                       case 10:
 
                                   second_player_field[point_y][point_x] = '0';
                                   if (second_player_field[point_y + 1][point_x] != '#')
                                       second_player_field[point_y + 1][point_x] = '+';
                                   if (second_player_field[point_y - 1][point_x] != '#')
                                       second_player_field[point_y - 1][point_x] = '+';
 
                                   if (second_player_field[point_y][point_x - 1] != '#') {
                                       second_player_field[point_y][point_x - 1] = '+';
                                       if (second_player_field[point_y - 1][point_x - 1] != '#')
                                           second_player_field[point_y - 1][point_x - 1] = '+';
                                       if (second_player_field[point_y + 1][point_x - 1] != '#')
                                           second_player_field[point_y + 1][point_x - 1] = '+';
                                   }
                                   if (second_player_field[point_y][point_x + 1] != '#') {
                                       second_player_field[point_y][point_x + 1] = '+';
                                       if (second_player_field[point_y - 1][point_x + 1] != '#')
                                           second_player_field[point_y - 1][point_x + 1] = '+';
                                       if (second_player_field[point_y + 1][point_x + 1] != '#')
                                           second_player_field[point_y + 1][point_x + 1] = '+';
                                   }
 
 
                           if (ships_1x_num == 1) {
                               ships_1x = false;
                           } else {
                               ships_1x_num -= 1;
                           }
                           break;
                   }
               }
               break;
     } // switch(choise)
 
     mini_reset();
}

void reset() {
    mini_reset();
    ship_4x = true;
    ships_3x = true;
    ships_2x = true;
    ships_1x = true;
    ships_3x_num = 2;
    ships_2x_num = 3;
    ships_1x_num = 4;

}

void building_battle_map_first_player () {
     clear();
     attron(COLOR_PAIR(1));
     printw("\t\t\tFirst player\n\n\n");
     for (int i = 0; i < HEIGHT; i++) {
         printw("\t\t     ");
         for (int j = 0; j < WIDTH; j++) {
             if (j == WIDTH - 1) {
                 printw("\n");
             } else {
                 
                 if (first_player_battle_field[i][j] == 'O') {                
                    attron(COLOR_PAIR(2));
                 }
                 if (first_player_battle_field[i][j] == 'X') {
                    attron(COLOR_PAIR(4));
                 } 
                 printw("%c", first_player_battle_field[i][j]);
                     attroff(COLOR_PAIR(2));
                     attroff(COLOR_PAIR(4));
                    
             }
         }
     }

     printw("\n\n\t\t   Use WASD to shouting");
     printw("\n\t\t  Press f to make a point");
     printw("\n\t\t  Press Enter to shouting");
}

void battle_map_for_first_player() {
    
    int a = '-';
    while (a != 10) {

    if (first_player_battle_field[point_y][point_x] != 'X'
       && first_player_battle_field[point_y][point_x] != '+') {
        first_player_battle_field[point_y][point_x] = 'O';
    } else {
        while (first_player_battle_field[point_y][point_x] != ' ') {
            point_x++;
            if (point_x == WIDTH - 2) {
                point_x = 1;
                point_y++;
            }
        }
        first_player_battle_field[point_y][point_x] = 'O';
    }
    
    
    

    
        building_battle_map_first_player();
        a = getch();

        switch (a) { // switch 1
    
        case 's':
            if (point_y + 2 < HEIGHT) {
                if (first_player_battle_field[point_y + 1][point_x] == ' ') {
                    first_player_battle_field[point_y][point_x] = ' ';
                    first_player_battle_field[point_y + 1][point_x] = 'O';
                    point_y += 1;
                    
                } else {
                    int j = point_y + 1;
                    while (j + 2 < HEIGHT) {
                        if (first_player_battle_field[j + 1][point_x] == ' ') {
                            first_player_battle_field[point_y][point_x] = ' ';
                            first_player_battle_field[j + 1][point_x] = 'O';
                            point_y = j + 1;
                            j = HEIGHT;
                        }
                        j++;
                    }
                }
            }
              break;
          case 'w':
              if (point_y - 1 != 0) {
                  if (first_player_battle_field[point_y - 1][point_x] == ' ') {
                      first_player_battle_field[point_y][point_x] = ' ';
                      first_player_battle_field[point_y - 1][point_x] = 'O';
                      point_y -= 1;
                  } else {
                      int j = point_y - 1;
                      while (j - 1 > 0) {
                          if (first_player_battle_field[j - 1][point_x] == ' ') {
                              first_player_battle_field[point_y][point_x] = ' ';
                              first_player_battle_field[j - 1][point_x] = 'O';
                              point_y = j - 1;
                              j = 0;
                          }
                          j--;
                      }
                  }
              }
             break;
          case 'd':

             if (point_x + 1 != WIDTH - 2) {
                 if (first_player_battle_field[point_y][point_x + 1] == ' ') {
                     first_player_battle_field[point_y][point_x + 1] = 'O';
                     first_player_battle_field[point_y][point_x] = ' ';
                     point_x += 1;
                 } else {
                     int j = point_x + 2;
                     while (j + 2 < WIDTH) {
                         if (first_player_battle_field[point_y][j] == ' ') {
                             first_player_battle_field[point_y][j] = 'O';
                             first_player_battle_field[point_y][point_x] = ' ';
                             point_x = j;
                             j = WIDTH;
                         }
                         j++;
                     }
                 }
             }

             break;
             case 'a':
             if (point_x - 1 != 0) {
                 if (first_player_battle_field[point_y][point_x - 1] == ' ') {
                     first_player_battle_field[point_y][point_x - 1] = 'O';
                     first_player_battle_field[point_y][point_x] = ' ';
                     point_x -= 1;
                 } else {
                     int j = point_x;
                     while (j - 1 > 0) {
                         if (first_player_battle_field[point_y][j - 1] == ' ') {
                             first_player_battle_field[point_y][point_x] = ' ';
                             first_player_battle_field[point_y][j - 1] = 'O';
                             point_x = j - 1;
                             j = 0;
                         }
                         j--;
                     }
                 }
             }
            break;
            case 'f':
                first_player_battle_field[point_y][point_x] = '+';

                break;
            case 10:
                if (second_player_field[point_y][point_x] == '0') {
                    first_player_battle_field[point_y][point_x] = 'X';
                    first_points++;
                    if (first_points == 20) {
                        GAME = false;
                    }
                } else {
                    first_player_battle_field[point_y][point_x] = '+';
                    turn = false;
                }
        } // switch 1
        
    }
    mini_reset();

}

void building_battle_map_second_player () {
     clear();
     attron(COLOR_PAIR(1));
     printw("\t\t\tSecond player\n\n\n");
     for (int i = 0; i < HEIGHT; i++) {
         printw("\t\t     ");
         for (int j = 0; j < WIDTH; j++) {
             if (j == WIDTH - 1) {
                 printw("\n");
             } else {

                 if (second_player_battle_field[i][j] == 'O') {
                    attron(COLOR_PAIR(2));
                 }
                 if (second_player_battle_field[i][j] == 'X') {
                    attron(COLOR_PAIR(4));
                 }
                 printw("%c", second_player_battle_field[i][j]);
                     attroff(COLOR_PAIR(2));
                     attroff(COLOR_PAIR(4));
             }
         }
     } 
     printw("\n\n\t\t   Use WASD to shouting");
     printw("\n\t\t  Press f to make a point");
     printw("\n\t\t  Press Enter to shouting");
}

void battle_map_for_second_player() {

     int a = '-';
     while (a != 10) {
 
     if (second_player_battle_field[point_y][point_x] != 'X'
        && second_player_battle_field[point_y][point_x] != '+') {
         second_player_battle_field[point_y][point_x] = 'O';
     } else {
         while (second_player_battle_field[point_y][point_x] != ' ') {
             point_x++;
             if (point_x == WIDTH - 2) {
                 point_x = 1;
                 point_y++;
             }
         }
         second_player_battle_field[point_y][point_x] = 'O';
     }
 
 
 
 
 
         building_battle_map_second_player();
         a = getch();
 
         switch (a) { // switch 1
 
         case 's':
             if (point_y + 2 < HEIGHT) {
                 if (second_player_battle_field[point_y + 1][point_x] == ' ') {
                     second_player_battle_field[point_y][point_x] = ' ';
                     second_player_battle_field[point_y + 1][point_x] = 'O';
                     point_y += 1;
 
                 } else {
                     int j = point_y + 1;
                     while (j + 2 < HEIGHT) {
                         if (second_player_battle_field[j + 1][point_x] == ' ') {
                             second_player_battle_field[point_y][point_x] = ' ';
                             second_player_battle_field[j + 1][point_x] = 'O';
                             point_y = j + 1;
                             j = HEIGHT;
                         }
                         j++;
                     }
                 }
             }
               break;
           case 'w':
               if (point_y - 1 != 0) {
                   if (second_player_battle_field[point_y - 1][point_x] == ' ') {
                       second_player_battle_field[point_y][point_x] = ' ';
                       second_player_battle_field[point_y - 1][point_x] = 'O';
                       point_y -= 1;
                   } else {
                       int j = point_y - 1;
                       while (j - 1 > 0) {
                           if (second_player_battle_field[j - 1][point_x] == ' ') {
                               second_player_battle_field[point_y][point_x] = ' ';
                               second_player_battle_field[j - 1][point_x] = 'O';
                               point_y = j - 1;
                               j = 0;
                           }
                           j--;
                       }
                   }
               }
              break;
           case 'd':
 
              if (point_x + 1 != WIDTH - 2) {
                  if (second_player_battle_field[point_y][point_x + 1] == ' ') {
                      second_player_battle_field[point_y][point_x + 1] = 'O';
                      second_player_battle_field[point_y][point_x] = ' ';
                      point_x += 1;
                  } else {
                      int j = point_x + 2;
                      while (j + 2 < WIDTH) {
                          if (second_player_battle_field[point_y][j] == ' ') {
                              second_player_battle_field[point_y][j] = 'O';
                              second_player_battle_field[point_y][point_x] = ' ';
                              point_x = j;
                              j = WIDTH;
                          }
                          j++;
                      }
                  }
              }
 
              break;
              case 'a':
              if (point_x - 1 != 0) {
                  if (second_player_battle_field[point_y][point_x - 1] == ' ') {
                      second_player_battle_field[point_y][point_x - 1] = 'O';
                      second_player_battle_field[point_y][point_x] = ' ';
                      point_x -= 1;
                  } else {
                      int j = point_x;
                      while (j - 1 > 0) {
                          if (second_player_battle_field[point_y][j - 1] == ' ') {
                              second_player_battle_field[point_y][point_x] = ' ';
                              second_player_battle_field[point_y][j - 1] = 'O';
                              point_x = j - 1;
                              j = 0;
                          }
                          j--;
                      }
                  }
              }
             break;
              case 'f':
                second_player_battle_field[point_y][point_x] = '+';

                break;
             case 10:
                 if (first_player_field[point_y][point_x] == '0') {
                     second_player_battle_field[point_y][point_x] = 'X';
                     second_points++;
                     if (second_points == 20) {
                        GAME = false;
                     }
                 } else {
                     second_player_battle_field[point_y][point_x] = '+';
                     turn = false;
                 }
         } // switch 1
 
     }
     mini_reset();
 
}






