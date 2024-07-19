//
//  main.c
//  
//
//  Created by Ömercan Kahveci on 14.04.2022.
//
// 2453298 omercankahveci
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollADice(void)//ok
{
    int dice;
    return dice=1+rand()%6;
}
int play_computer(int scoreC,int roundCounter)//ok
{
    int dice,i=0;
    int dice1,dice2,dice3,dice4,dice5,balutdice=1,balutcheck=0,smallSPossibility=0,largeSPossibility=0,fivesPossibility=0,sixesPossibility=0,wrong1=0,wrong2=0,wrong3=0,wrong4=0,wrong5=0,lucky=0;
    int score=0;
    printf("\nround %d my turn",roundCounter+1);
    printf("\n*******************************************\n");
    while(i<5)
        {   //rolling dices
            dice=rollADice();
            printf("[Dice %d]: %d",i+1,dice);
            if(i==0)
            {
                dice1=dice;
                balutdice*=dice1;
                if(dice1==1)
                {
                    smallSPossibility++;
                }
                else if (dice1==2)
                {
                    largeSPossibility++;
                }
                else if (dice1==5)
                {
                    fivesPossibility++;
                }
                else if (dice1==6)
                {
                    sixesPossibility++;
                }
                else
                {
                    wrong1++;
                }
            } //second dice check
            else if (i==1)
            {
                dice2=dice;
                if (balutdice==dice2)
                {
                    balutcheck++;//balut counter
                }
                if(dice2==2)
                {
                    smallSPossibility++;//small counter
                }
                else if(dice2==3)
                {
                    largeSPossibility++;//large counter
                }
                else if (dice2==5)
                {
                    fivesPossibility++;//fives counter
                }
                else if (dice2==6)
                {
                    sixesPossibility++;//sixes counter
                }
                else
                {
                        wrong2++;// check for rerolling
                }
            }//third dice check
            else if (i==2)
            {
                dice3=dice;
                if (balutdice==dice3)
                {
                    balutcheck++;
                }
                if (dice3==3)
                {
                    
                    smallSPossibility++;
                }
                else if (dice3==4)
                {
                    
                    largeSPossibility++;
                }
                else if (dice3==5)
                {
                    fivesPossibility++;
                }
                else if (dice3==6)
                {
                    sixesPossibility++;
                }
                else
                {
                    wrong3++;
                }
            }
            else if (i==3)
            {
                dice4=dice;
                if (balutdice==dice4)
                {
                    balutcheck++;
                }
                if(dice4==4)
                {
                    smallSPossibility++;
                }
                else if(dice4==5)
                {
                    largeSPossibility++;
                    fivesPossibility++;
                }
                else if (dice4==6)
                {
                    sixesPossibility++;
                }
                else
                {
                        wrong4++;
                }
            }
            else if (i==4)
            {
                dice5=dice;
                if (balutdice==dice5)
                {
                    balutcheck++;
                }
                if(dice5==5)
                {
                    smallSPossibility++;
                    fivesPossibility++;
                }
                else if (dice5==6)
                {
                    largeSPossibility++;
                    sixesPossibility++;
                }
                else
                {
                    wrong5++;
                }
            }
            
            i++;
        }
        if(smallSPossibility==4||largeSPossibility==4)// rerolling if they close
            {
                if(wrong1!=0)
                {
                    printf("\nRolled Dice 1…");
                    dice1=rollADice();
                    if (dice1==1)
                    {
                        lucky++;
                        smallSPossibility++;
                    }
                    else if(dice1==2)
                    {
                        lucky++;
                        largeSPossibility++;
                    }
                    
                }
                else if (wrong2!=0)
                {
                    printf("\nRolled Dice 2…");
                    dice2=rollADice();
                    if (dice2==2)
                    {
                        lucky++;
                        smallSPossibility++;
                    }
                    else if(dice2==3)
                    {
                        lucky++;
                        largeSPossibility++;
                    }
                    
                }
                else if (wrong3!=0)
                {
                    printf("\nRolled Dice 3…");
                    dice3=rollADice();
                    if (dice3==3)
                    {
                        lucky++;
                        smallSPossibility++;
                    }
                    else if(dice3==4)
                    {
                        lucky++;
                        largeSPossibility++;
                    }
                    

                }
                else if (wrong4!=0)
                {
                    printf("\nRolled Dice 4…");
                    dice4=rollADice();
                    if (dice4==4)
                    {
                        lucky++;
                        smallSPossibility++;
                    }
                    else if(dice4==5)
                    {
                        lucky++;
                        largeSPossibility++;
                    }
                }
                else if (wrong5!=0)
                {
                    printf("\nRolled Dice 5…");
                    dice5=rollADice();
                    if (dice5==5)
                    {
                        lucky++;
                        smallSPossibility++;
                        
                    }
                    else if(dice5==6)
                    {
                        lucky++;
                        largeSPossibility++;
                    }
                    
                }
                if (lucky!=0)
                {
                    printf("\nLucky me!!");
                }
            }
    //scoring
    else if (smallSPossibility==5)
    {
        score+=15;
    }
    else if (largeSPossibility==5)
    {
        score+=20;
    }
    else if(fivesPossibility>=2)
    {
        score=score+fivesPossibility*5;
    }
    else if (sixesPossibility>=2)
    {
        score=score+sixesPossibility*6;
    }
    else if (balutcheck==4)
    {
        score=score+(balutdice*5)+20;
    }
    return score;
        
}

int whoWillStart(void)//ok
{
    int turndice1,turndice2;
    // rolling dices
    turndice1=1+rand()%6;
    turndice2=1+rand()%6;
    printf("\nI have rolled the dice and got %d!",turndice1);
    printf("\nI have rolled the dice for you and you got %d!",turndice2);
    // who will start
    if(turndice1>turndice2)
    {
        return 0;
    }
    else if(turndice2>turndice1)
    {
        return 1;
    }
    else
    {
        printf("\nwe got same!");
        printf("\nwrerolling...");

        return whoWillStart();
    }
}
int play_user(int roundCounter)//user da kaldın checklerr hazır veri cekip tutma kaldı
{
    int dice,i=0,k=0;
    char keepDice='n';
    int balutdice=1,dice1=1,dice2=1,dice3=1,dice4=1,dice5=1,smallSPossibility=0,largeSPossibility=0,fivesPossibility=0,sixesPossibility=0;
    int score=0,fullKeep=0,keep11=0,keep12=0,keep13=0,keep14=0,keep15=0,keep22=0,keep23=0,keep24=0,keep25=0;
    int keep33=0,keep34=0,keep35=0,keep44=0,keep45=0,keep55=0;
    fflush(stdin);
    printf("\nround %d your turn",roundCounter+1);
    printf("\n*******************************************");
    printf("\nAre you ready to play! ");
    printf("\nI rolled them for you and you got\n");
    // rolling dices for first turn
    dice1*=1+rand()%6;
    dice2*=1+rand()%6;
    dice3*=1+rand()%6;
    dice4*=1+rand()%6;
    dice5*=1+rand()%6;
    printf("\n[dice1]: %d [dice2]: %d [dice3]: %d [dice4]: %d [dice5]: %d",dice1,dice2,dice3,dice4,dice5);
    while(i<3)
    {
        printf("\nWhich ones you want to keep? ");
        while(k<=5)
        {
            scanf("%c",&keepDice);
        if(k==0)//keeping check for dice 1
        {
            if(keepDice=='1')
            {   keep11++;}
            else if (keepDice=='2')
            {   keep12++;}
            else if (keepDice=='3')
            {   keep13++;}
            else if (keepDice=='4')
            {    keep14++;}
            else if (keepDice=='5')
            {   keep15++;}
        }
        else if(k==1)// keeeping check for dice 2
        {
            if (keepDice=='2')
            {   keep22++;}
            else if (keepDice=='3')
            {   keep23++;}
            else if (keepDice=='4')
            {    keep24++;}
            else if (keepDice=='5')
            {   keep25++;}
        }
        else if (k==2)//keeping check for dice 3
        {
            if (keepDice=='3')
            {   keep33++;}
            else if (keepDice=='4')
            {    keep34++;}
            else if (keepDice=='5')
            {   keep35++;}
        }
        else if(k==3)//keeping check for dice 4
        {
            if (keepDice=='4')
            {    keep44++;}
            else if (keepDice=='5')
            {   keep45++;}
        }
        else if (k==4)//keeping check for dice 5
        {
            if (keepDice=='5')
            {   keep55++;}
        }
            if(keepDice=='\n')//this  eliminates line feeds
            {
                break;
            }
            if(keepDice==32)//this eliminates spaces
            {
                continue;
            }
            k++;

        }
    if(keep11==1)//starting with dice 1
    {
        if (keep23==1)//3
        {
            if(keep34==1)//4
            {
                    
                dice2=1+rand()%6;
                dice5=1+rand()%6;
                printf("\n[dice2] %d [dice5]: %d",dice2,dice5);
            }
            else if (keep35==1)//5
            {
                dice2=1+rand()%6;
                dice4=1+rand()%6;
                printf("\n[dice2] %d [dice4]: %d",dice2,dice4);
            }
            else
            {
                dice2=1+rand()%6;
                dice4=1+rand()%6;
                dice5=1+rand()%6;
                printf("\n[dice2] %d [dice4]: %d [dice5]: %d",dice2,dice4,dice5);
            }
        }
        else if(keep22==1)//2
        {
            if(keep33==1)//3
            {
                if(keep44==1)
                {
                    dice5=1+rand()%6;
                    printf("\n[dice5]: %d",dice5);
                }
                else
                {
                    dice4=1+rand()%6;
                    dice5=1+rand()%6;
                    printf("\n[dice4]: %d [dice5]: %d",dice4,dice5);
                }
            }
            else
            {
                dice3=1+rand()%6;
                dice4=1+rand()%6;
                dice5=1+rand()%6;
                printf("\n[dice3]: %d [dice4]: %d [dice5]: %d",dice3,dice4,dice5);
                
            }
        }
        else if (keep24==1)
        {
            if(keep55==1)
            {
                dice3=1+rand()%6;
                printf("\n[dice3]: %d ",dice3);
            }
            else{
            dice3=1+rand()%6;
            dice5=1+rand()%6;
                printf("\n[dice3]: %d [dice5]: %d",dice3,dice5);}
            
        }
        else if (keep25==1)
        {
            dice2=1+rand()%6;
            dice3=1+rand()%6;
            dice4=1+rand()%6;
            printf("\n[dice2]: %d [dice3]: %d [dice4]: %d",dice2,dice3,dice4);
        }
        else
        {
            dice2=1+rand()%6;
            dice3=1+rand()%6;
            dice4=1+rand()%6;
            dice5=1+rand()%6;
            printf("\n[dice2]: %d [dice3]: %d [dice4]: %d [dice5]: %d",dice2,dice3,dice4,dice5);
        }
    }
    else if(keep12==1)// starting with dice 2
    {
        if (keep33==1)
        {
            dice4=1+rand()%6;
            dice5=1+rand()%6;
            printf("\n[dice4]: %d [dice5]: %d",dice4,dice5);
        }
        else if (keep44)
        {
            dice3=1+rand()%6;
            dice5=1+rand()%6;
            printf("\n[dice3]: %d [dice5]: %d",dice3,dice5);
        }
        else
        {
            dice2=1+rand()%6;
            dice3=1+rand()%6;
            dice4=1+rand()%6;
            dice5=1+rand()%6;
            printf("\n[dice2]: %d [dice3]: %d [dice4]: %d [dice5]: %d",dice2,dice3,dice4,dice5);
        }
        
    }
    // scoring part
    balutdice=dice1;
    if(balutdice==dice1&&balutdice==dice2&&balutdice==dice3&&balutdice==dice4&&balutdice==dice5)
    {
        score=score+(balutdice*5)+20;
        
    }
    else if(dice1==1)
    {
        smallSPossibility++;
        if(dice2==2)
        {
            smallSPossibility++;
        }
        else if (dice3==3)
        {
            
            smallSPossibility++;
        }
        else if(dice4==4)
        {
            smallSPossibility++;
        }
        else if(dice5==5)
        {
            smallSPossibility++;
            fivesPossibility++;
        }
    }
    else if (dice1==2)
    {
        largeSPossibility++;
        if(dice2==3)
        {
            largeSPossibility++;
        }
        else if (dice3==4)
        {
            
            largeSPossibility++;
        }
        else if(dice4==5)
        {
            largeSPossibility++;
            fivesPossibility++;
        }
        else if (dice5==6)
        {
            largeSPossibility++;
            sixesPossibility++;
        }
    }
    if (dice1==5)
    {
        fivesPossibility++;
    }
    else if (dice1==6)
    {
        sixesPossibility++;
    }
    if (dice2==5)
    {
        fivesPossibility++;
    }
    else if (dice2==6)
    {
        sixesPossibility++;
    }
    if (dice3==5)
    {
        fivesPossibility++;
    }
    else if (dice3==6)
    {
        sixesPossibility++;
    }
    if(dice4==5)
    {
        fivesPossibility++;
    }
    else if (dice4==6)
    {
        sixesPossibility++;
    }
    if(dice5==5)
    {
        
        fivesPossibility++;
    }
    else if (dice5==6)
    {
        
        sixesPossibility++;
    }
    else if (smallSPossibility==5)
    {
        score+=15;
    }
    else if (largeSPossibility==5)
    {
        score+=20;
    }
    else if(fivesPossibility>=2)
    {
        score=score+fivesPossibility*5;
    }
    else if (sixesPossibility>=2)
    {
        score=score+sixesPossibility*6;
    }
        i++;
    }
    return score;
}

void scoresheet(int rounds,int roundCounter,int scoreComputer,int scorePlayer)
{   int totalScoreComputer=0,totalscorePlayer=0;
    // calculating total score
    totalScoreComputer+=scoreComputer;
    totalscorePlayer+=scorePlayer;
    if (roundCounter+1<=rounds)
    {   // who is the winner
        if(roundCounter+1==rounds)
        {
            if(totalscorePlayer>totalScoreComputer)
            {
                printf("\nYou are the winner!");
            }
            else if (totalScoreComputer>totalscorePlayer)
            {
                printf("\nI am the winnter!");
            }
            else
            {
                printf("\nWe are equal!");
            }
        }
        else
        {
        printf("\nour score sheet after round %d",rounds);
        printf("\n*********************************************");
        printf("\nmy score your score");
        printf("\n%3d %9d\n",totalScoreComputer,totalscorePlayer);
        }
    }
    
}
int main() {
    int turn,rounds,roundCounter=0,cStarted=0,uStarted=0;
    int scoreComputer,scoreC=0,scorePlayer;
    srand(time(NULL));
    printf("\nWelcome to the Balut game.");
    printf("\nLets get started!");
    printf("\nHow many rounds would you like to play?");
    scanf("%d",&rounds);
    turn=whoWillStart();
    // checking turn is 1 or 0 by %2
    if (turn%2==0)
    {
        cStarted=1;
     
    }
    else if(turn%2==1)
    {
        uStarted=1;
        
    }
    while((roundCounter!=rounds)&&(uStarted==1||cStarted==1))
    {
        if (uStarted==1)
        {
            scorePlayer=play_user(roundCounter);
            printf("\nYour score: %d",scorePlayer);
            scoreComputer=play_computer(scoreC,roundCounter);
            printf("\nMy score: %d",scoreComputer);
            scoresheet(rounds, roundCounter, scoreComputer, scorePlayer);
        }
        else if(cStarted==1)
        {
            scoreComputer=play_computer(scoreC,roundCounter);
            printf("\nMy score: %d\n",scoreComputer);
            scorePlayer=play_user(roundCounter);
            printf("\nYour score: %d\n",scorePlayer);
            scoresheet(rounds, roundCounter, scoreComputer, scorePlayer);
        }
        roundCounter++;
    }
        
    return 0;
}
