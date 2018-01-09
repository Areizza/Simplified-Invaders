/*
Title: Assignment-7
Author: Priscilla Lo
Objective: To make use of Singleton, Observer, and Factory design patterns in an interactive game.
In this game, the player needs to destroy all the enemy bacteria within 2 minutes or else they die will
contract the deadly disease and die.
SINGLETON - timer
OBSERVER - used to move the player ship left and right, press up to shoot
FACTORY - generates enemies
*/

#include "gotoXY.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Collision.h"
#include "TimerMgr.h"

//GAME STATES
enum States { MainMenu, Play, Story, Quit };

void TimerPrint();

bool TimerEnded = false;

void main()
{
	//VARIABLES
	States current = States::MainMenu;
	int select = 0;
	InputManager* inputMgr = new InputManager();
	Ship* player = new Ship(inputMgr);
	vector<Enemy*> Enemies;

	bool win = false; //bools for end of game
	bool lose = false;
	int count = 0;
	int setTime = 0;
	

	inputMgr->Attach(75); //left
	inputMgr->Attach(77); //right
	inputMgr->Attach(72); //up to shoot
	inputMgr->SetListeners(player);

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 525, 650, TRUE);

	//LOOPED GAMEPLAY
	while (0 == 0)
	{
		//MAIN MENU
		if (select == 0 || current == MainMenu)
		{
			system("CLS");
			SetConsoleTextAttribute(hstdout, 12);
			cout << "                 THE DARK END AWAITS..." << endl;
			SetConsoleTextAttribute(hstdout, 15);
			cout << "--------------------------------------------------------" << endl;
			SetConsoleTextAttribute(hstdout, 23);
			gotoXY(26, 3);
			cout << (char)179 << endl;
			gotoXY(25, 4);
			cout << "/ \\" << endl;
			gotoXY(24, 5);
			cout << "/___\\" << endl;
			gotoXY(24, 6);
			cout << (char)179 << "   " << (char)179 << endl;
			gotoXY(24, 7);
			cout << (char)179 << "   " << (char)179 << endl;
			gotoXY(23, 8);
			cout << "/" << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << "\\" << endl << endl;
			SetConsoleTextAttribute(hstdout, 15);
			cout << "--------------------------------------------------------" << endl;
			cout << "        [1] - Play    [2] - Story     [3] - Quit\n" << endl;
			cin >> select;
		}

		//PLAY GAME
		if (select == 1 || current == Play)
		{
			system("CLS");

			SetConsoleTextAttribute(hstdout, 12);
			cout << "What level of horror would you like to visit?" << endl;
			SetConsoleTextAttribute(hstdout, 15);
			cout << "--------------------------------------------------------" << endl;
			cout << "[1] - Mild (Weakling)   [2] - Normal   [3] - Nightmare" << endl;
			cin >> count;

			system("CLS");
			//draw ship at initial posiion
			player->drawShip();

			//draws ground
			gotoXY(0, 31);
			for (int i = 0; i < 60; i++)
			{
				cout << "-";
			}

			//FACTORY generated enemies
			if (count == 1)
			{
				setTime = 60000; //set timer to 1min
				for (int i = 0; i < 2; i++) //5 big enemies
				{
					Enemies.push_back(EnemyFactory::GetInstance()->createEnemy(EnemyTypes::Big));
				}

				for (int i = 0; i < 3; i++) //10 smol enemies
				{
					Enemies.push_back(EnemyFactory::GetInstance()->createEnemy(EnemyTypes::Smol));
				}
			}
			else if (count == 2)
			{
				setTime = 30000; //set timer for 30 seconds 
				for (int i = 0; i < 5; i++) //5 big enemies
				{
					Enemies.push_back(EnemyFactory::GetInstance()->createEnemy(EnemyTypes::Big));
				}

				for (int i = 0; i < 10; i++) //10 smol enemies
				{
					Enemies.push_back(EnemyFactory::GetInstance()->createEnemy(EnemyTypes::Smol));
				}
			}
			else if (count == 3)
			{
				setTime = 35000; //set timer for 35 seconds 
				for (int i = 0; i < 10; i++) //5 big enemies
				{
					Enemies.push_back(EnemyFactory::GetInstance()->createEnemy(EnemyTypes::Big));
				}

				for (int i = 0; i < 20; i++) //10 smol enemies
				{
					Enemies.push_back(EnemyFactory::GetInstance()->createEnemy(EnemyTypes::Smol));
				}
			}

			//SINGLETON
			TimerMgr::GetInstance()->createTimer(setTime, TimerPrint); //set for 30 seconds 
			
			//loop while player has not killed all the enemies (did not win) and while the timer is still ongoing
			while (win == lose && TimerEnded == false)
			{
				//displays information
				SetConsoleTextAttribute(hstdout, 12);
				gotoXY(0, 0);
				cout << "Time Elapsed: ";
				TimerMgr::GetInstance()->tickTimers();

				gotoXY(40, 0);
				cout << "                    ";
				gotoXY(40, 0);
				cout << "Enemies Left: " << Enemies.size();
				SetConsoleTextAttribute(hstdout, 15);

				if (_kbhit()) //OBSERVER gets keys pressed
				{
					inputMgr->Notify(_getch());
				}

				//drawing and moving the bullets fired
				for (int i = 0; i < player->Bullets.size(); i++)
				{
					player->Bullets[i]->erasePrev(); //erases previous bullet that was drawn

					if (player->Bullets[i]->boundaryHit() == false) //move bullet only if it hasnt already reached the boundary, else remove it
					{
						player->Bullets[i]->moveBullet();

						for (int j = 0; j < Enemies.size(); j++) //check collision for all the enemies in the vector
						{
							if (collision(*player->Bullets[i], *Enemies[j]) == true) //if bullet collides with an enemy, enemy is deleted
							{
								Enemies.erase(Enemies.begin() + j);

								if (Enemies.size() == 0)
								{
									win = true; //player wins when all the enemies are dead
								}

							}
						}
						player->Bullets[i]->drawBullet(); //draw bullet at new location
					}
					else
					{
						player->Bullets.erase(player->Bullets.begin() + i);
					}
				}

				Sleep(25); //rest
			}

			if (win == true) //message when player successfully defeated all the enemies within the time limit
			{
				gotoXY(0, 32);
				cout << "Congratulations, you survived!!!\nNow you'll have to write the exam of death!";
				gotoXY(0, 35);
				cout << "[ENTER 1 INTEGER TO RETURN TO MENU]" << endl;	
			}
			else
			{
				gotoXY(0, 32);
				cout << "GAME OVER. Too bad, you'll have to retake this course again.";
				gotoXY(0, 34);
				cout << "[ENTER 1 INTEGER TO RETURN TO MENU]" << endl;
			}

			//reset variables for future games
			count = 0;
			TimerEnded = false;
			win = false;
			Enemies.clear();
			player->m_X = 30;
			player->Bullets.clear();
			TimerMgr::m_TimerMgr = 0;

		
			//input selection from user
			cin >> select;
		}

		//STORY
		if (select == 2 || current == Story)
		{
			system("CLS");
			SetConsoleTextAttribute(hstdout, 12);
			cout << "THE DARK END AWAITS" << endl;
			SetConsoleTextAttribute(hstdout, 15);
			cout << "--------------------------------------------------------" << endl;
			cout << "Once upon a time in a land far away..." << endl;
			cout << "It was Assignment 7. The dreaded final assignment of the " << endl;
			cout << "semester. The student has been shrunk down and sent on a " << endl;
			cout << "journey to a hostile microbe. Armed only with their poorly" << endl;
			cout << "designed spaceship, the sleep-deprived student must fight off" << endl;
			cout << "the deadly bacteria before they contract the disease and must" << endl;
			cout << "also be terminated. The only advice that the professor gave " << endl;
			cout << "is: 'get good~'" << endl << endl;
			cout << "Good luck! :)" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << "[ENTER 1 INTEGER TO RETURN TO MENU]" << endl;
			cin >> select;
		}

		//QUIT
		if (select == 3 || current == Quit)
		{
			system("CLS");
			cout << "Terminating." << endl;

			//deleting
			delete player;
			player = nullptr;
			for (int i = 0; i < Enemies.size(); i++)
			{
				delete Enemies[i];
			}
			Enemies.clear();
			delete inputMgr;
			inputMgr = nullptr;

			break;
		}
	}
}

//write timer end message
void TimerPrint()
{
	gotoXY(0, 1);
	cout << "Time's up! You're DEAD." << endl;
	TimerEnded = true;
}