// Challenges : The list of your challenges password
// challengesSize[i][j] is the size of the challenge number i part j
// challenges[i][j] is the password string of the challenge number i part j

byte challengesStatus[8] = {0,0,0,0,0,0,0,0};

const byte challengesSize[8][2] =
                            {{4,3}
                            ,{4,0}
                            ,{0,0}
                            ,{0,0}
                            ,{0,0}
                            ,{0,0}
                            ,{0,0}
                            ,{0,0}
                            };

const char challenges[8][2][8] =
                            {{{'1','2','3','4'},{'7','8','9'}}
                            ,{{'4','3','2','1'},{0,0}}
                            ,{{0,0},{0,0}}
                            ,{{0,0},{0,0}}
                            ,{{0,0},{0,0}}
                            ,{{0,0},{0,0}}
                            ,{{0,0},{0,0}}
                            ,{{0,0},{0,0}}
                            };

