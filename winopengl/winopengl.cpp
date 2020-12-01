#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "freeglut.lib")

//-----Includes-----
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <math.h>
#include <ctime>
#include <string>
#include <SOIL.h>
#include <chrono>
#include <vector>
#include <fstream>
#include "resource.h"
//-----

//-----Start variables-----
using namespace std;

GLint Width = 1280, Height = 720;
float xmousepos = 0.0, ymousepos = 0.0;
bool mousebuttonstate, exitbuttonstate = 0, notcont = 0,
gamestart = 0, cardTakenButton[12] = { 0 }, ifset = 0, startgame = 0, recordmenu = 0, tryagainerror = 0, notcontoneset = 0, _helper = 0, helpercont = 0;
string path[81] = { "Data\\c1b0.png", "Data\\c1b05.png", "Data\\c1b1.png", "Data\\c1g0.png", "Data\\c1g05.png", "Data\\c1g1.png", "Data\\c1r0.png", "Data\\c1r05.png", "Data\\c1r1.png", "Data\\c2b0.png",
						"Data\\c2b05.png","Data\\c2b1.png", "Data\\c2g0.png", "Data\\c2g05.png", "Data\\c2g1.png", "Data\\c2r0.png", "Data\\c2r05.png", "Data\\c2r1.png", "Data\\c3b0.png", "Data\\c3b05.png",
						"Data\\c3b1.png", "Data\\c3g0.png", "Data\\c3g05.png", "Data\\c3g1.png", "Data\\c3r0.png", "Data\\c3r05.png", "Data\\c3r1.png", "Data\\r1b0.png", "Data\\r1b05.png", "Data\\r1b1.png",
						"Data\\r1g0.png", "Data\\r1g05.png", "Data\\r1g1.png", "Data\\r1r0.png", "Data\\r1r05.png", "Data\\r1r1.png", "Data\\r2b0.png", "Data\\r2b05.png", "Data\\r2b1.png", "Data\\r2g0.png",
						"Data\\r2g05.png", "Data\\r2g1.png", "Data\\r2r0.png", "Data\\r2r05.png", "Data\\r2r1.png", "Data\\r3b0.png", "Data\\r3b05.png", "Data\\r3b1.png", "Data\\r3g0.png", "Data\\r3g05.png",
						"Data\\r3g1.png", "Data\\r3r0.png", "Data\\r3r05.png", "Data\\r3r1.png", "Data\\t1b0.png", "Data\\t1b05.png", "Data\\t1b1.png", "Data\\t1g0.png", "Data\\t1g05.png", "Data\\t1g1.png",
						"Data\\t1r0.png", "Data\\t1r05.png", "Data\\t1r1.png", "Data\\t2b0.png", "Data\\t2b05.png", "Data\\t2b1.png", "Data\\t2g0.png", "Data\\t2g05.png", "Data\\t2g1.png", "Data\\t2r0.png",
						"Data\\t2r05.png", "Data\\t2r1.png", "Data\\t3b0.png", "Data\\t3b05.png", "Data\\t3b1.png", "Data\\t3g0.png", "Data\\t3g05.png", "Data\\t3g1.png", "Data\\t3r0.png", "Data\\t3r05.png", "Data\\t3r1.png" };
GLuint textures[81], isSetTexture;
int cardpressed = 0, setsnum = 0, secondsingame = 0, score = 0, isOneSetCardNum[3], helperCounter = 3;
chrono::duration<float> Time;

struct {
	int xpos[12] = { 420, 660, 900, 1140, 420, 660, 900, 1140, 420, 660, 900, 1140 };
	int ypos[12] = { 600, 600, 600, 600, 360, 360, 360, 360, 120, 120, 120, 120 };
}rectPos;
struct {
	int id;
	char shape;
	char num;
	char color;
	char shading;
	bool state;
}cards[81], cardsOnField[12], cardTaken[3], setCombination[3];
struct Record {
	string nickname;
	int score;
} record;
vector<Record> records;
//-----

//-----GLUT Control Funcs-----
void Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'
#define ENTER '\013'

	if (key == ESCAPE)
		exit(0);
}
void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mousebuttonstate = 1;
	}
	else
		mousebuttonstate = 0;

	//-----1st line-----
	if (xmousepos < 480 && xmousepos > 360 && ymousepos < 680 && ymousepos > 520 && mousebuttonstate == 1) {
		if (cardTakenButton[0] == 1) {
			cardTakenButton[0] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[0] = 1;
			cardTaken[cardpressed] = cardsOnField[0];
			cardpressed++;
		}
	}
	else if (xmousepos < 720 && xmousepos > 600 && ymousepos < 680 && ymousepos > 520 && mousebuttonstate == 1) {
		if (cardTakenButton[1] == 1) {
			cardTakenButton[1] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[1] = 1;
			cardTaken[cardpressed] = cardsOnField[1];
			cardpressed++;
		}
	}
	else if (xmousepos < 960 && xmousepos > 840 && ymousepos < 680 && ymousepos > 520 && mousebuttonstate == 1) {
		if (cardTakenButton[2] == 1) {
			cardTakenButton[2] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[2] = 1;
			cardTaken[cardpressed] = cardsOnField[2];
			cardpressed++;
		}
	}
	else if (xmousepos < 1200 && xmousepos > 1080 && ymousepos < 680 && ymousepos > 520 && mousebuttonstate == 1) {
		if (cardTakenButton[3] == 1) {
			cardTakenButton[3] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[3] = 1;
			cardTaken[cardpressed] = cardsOnField[3];
			cardpressed++;
		}
	}
	//-----
	//-----2nd line-----
	else if (xmousepos < 480 && xmousepos > 360 && ymousepos < 440 && ymousepos > 280 && mousebuttonstate == 1) {
		if (cardTakenButton[4] == 1) {
			cardTakenButton[4] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[4] = 1;
			cardTaken[cardpressed] = cardsOnField[4];
			cardpressed++;
		}
	}
	else if (xmousepos < 720 && xmousepos > 600 && ymousepos < 440 && ymousepos > 280 && mousebuttonstate == 1) {
		if (cardTakenButton[5] == 1) {
			cardTakenButton[5] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[5] = 1;
			cardTaken[cardpressed] = cardsOnField[5];
			cardpressed++;
		}
	}
	else if (xmousepos < 960 && xmousepos > 840 && ymousepos < 440 && ymousepos > 280 && mousebuttonstate == 1) {
		if (cardTakenButton[6] == 1) {
			cardTakenButton[6] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[6] = 1;
			cardTaken[cardpressed] = cardsOnField[6];
			cardpressed++;
		}
	}
	else if (xmousepos < 1200 && xmousepos > 1080 && ymousepos < 440 && ymousepos > 280 && mousebuttonstate == 1) {
		if (cardTakenButton[7] == 1) {
			cardTakenButton[7] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[7] = 1;
			cardTaken[cardpressed] = cardsOnField[7];
			cardpressed++;
		}
	}
	//-----
	//-----3rd line-----
	else if (xmousepos < 480 && xmousepos > 360 && ymousepos < 200 && ymousepos > 40 && mousebuttonstate == 1) {
		if (cardTakenButton[8] == 1) {
			cardTakenButton[8] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[8] = 1;
			cardTaken[cardpressed] = cardsOnField[8];
			cardpressed++;
		}
	}
	else if (xmousepos < 720 && xmousepos > 600 && ymousepos < 200 && ymousepos > 40 && mousebuttonstate == 1) {
		if (cardTakenButton[9] == 1) {
			cardTakenButton[9] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[9] = 1;
			cardTaken[cardpressed] = cardsOnField[9];
			cardpressed++;
		}
	}
	else if (xmousepos < 960 && xmousepos > 840 && ymousepos < 200 && ymousepos > 40 && mousebuttonstate == 1) {
		if (cardTakenButton[10] == 1) {
			cardTakenButton[10] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[10] = 1;
			cardTaken[cardpressed] = cardsOnField[10];
			cardpressed++;
		}
	}
	else if (xmousepos < 1200 && xmousepos > 1080 && ymousepos < 200 && ymousepos > 40 && mousebuttonstate == 1) {
		if (cardTakenButton[11] == 1) {
			cardTakenButton[11] = 0;
			cardTaken[cardpressed] = { 0 };
			cardpressed--;
		}
		else {
			cardTakenButton[11] = 1;
			cardTaken[cardpressed] = cardsOnField[11];
			cardpressed++;
		}
	}
	//-----
}
void mouseMove(int x, int y) {
	xmousepos = x;
	ymousepos = Height - y;
}
//-----

GLuint loadTexture(const char* fileName) {
	GLuint texture;
	texture = SOIL_load_OGL_texture(fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_POWER_OF_TWO);
	return texture;
}
void drawRect(GLint x, GLint y, GLint colorR, GLint colorG, GLint colorB) {
	glColor3ub(colorR, colorG, colorB);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(x - 60, y + 80);
	glVertex2f(x - 60, y - 80);
	glVertex2f(x + 60, y + 80);
	glVertex2f(x + 60, y - 80);
	glEnd();
}
void drawText(char* str, int x, int y, GLfloat red, GLfloat green, GLfloat blue) {
	int length, height;

	height = glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24) / 2;
	length = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)str) / 2;
	y -= height;
	x -= length;

	glColor3ub(red, green, blue);
	glRasterPos2d(x, y);
	int i = 0;
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)str);
}
void Init() {
	for (int i = 0; i < 81; i++) {
		textures[i] = loadTexture(path[i].c_str());
	}
	for (int i = 0; i < 12; i++) {
		cardsOnField[i].id = -1;
	}
	isSetTexture = loadTexture("Data\\set.png");
}
void gameCardsDrawFunc(int i, GLuint texture) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glColor3ub(255, 255, 255);
	glBegin(GL_QUAD_STRIP);

	glTexCoord2f(0, 0); glVertex2f(rectPos.xpos[i] - 55, rectPos.ypos[i] + 75);
	glTexCoord2f(0, 1); glVertex2f(rectPos.xpos[i] - 55, rectPos.ypos[i] - 75);
	glTexCoord2f(1, 0); glVertex2f(rectPos.xpos[i] + 55, rectPos.ypos[i] + 75);
	glTexCoord2f(1, 1); glVertex2f(rectPos.xpos[i] + 55, rectPos.ypos[i] - 75);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void staticMenuFunc();
void drawField();
void buttonsMenuEnableFunc();
void dynamicGameFunc();
void cardsOnFieldStartFunc();
void redraw();
void loadRecord();
void saveRecord();
void sortRecord();
int isOneSetOnField();
int helper();

//-----Main func-----
int main(int argc, char* argv[]) {
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");

	loadRecord();
	for (int i = 0; i < 81; i++) {
		cards[i].id = i;
		cards[i].shape = path[i][5];
		cards[i].num = path[i][6];
		cards[i].color = path[i][7];
		if (path[i][9] == '5')
			cards[i].shading = path[i][9];
		else
			cards[i].shading = path[i][8];
		cards[i].state = 0;
	}

	cout << path[30] << endl;
	cout << cards[30].color << " " << cards[30].shape << endl;

	//FreeConsole();
	RECT rect;
	GetWindowRect(GetDesktopWindow(), &rect);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_BORDERLESS | GLUT_CAPTIONLESS);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(rect.right / 2 - Width / 2, rect.bottom / 2 - Height / 2);//центрирование окна
	glutCreateWindow("Set Classic");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, Width, 0, Height, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(drawField);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(mouseButton);

	glutPassiveMotionFunc(mouseMove);
	Init();

	glutMainLoop();
}
//-----

string r(int _time) {
	string str;
	int t = _time / 60;
	str += ((t < 10) ? "0" : "") + to_string(t) + ":";

	t = _time % 60;
	str += ((t < 10) ? "0" : "") + to_string(t);

	return str;
}
void loadRecord() {
	ifstream fin;
	Record rec;
	fin.open("records.txt");
	while (!fin.eof()) {
		fin >> rec.nickname >> rec.score;
		if (rec.nickname == "") continue;
		records.push_back(rec);
		rec = { "", 0 };
	}
	fin.close();
}
void sortRecord() {
	for (int i = 0; i < (int)records.size(); i++)
		for (int j = 0; j < (int)records.size() - 1; j++)
			if (records[j].score < records[j + 1].score)
				swap(records[j], records[j + 1]);

	while (records.size() > 10) records.pop_back();
}
void saveRecord() {
	ofstream fout;
	fout.open("records.txt", ios::trunc);

	for (int i = 0; i < (int)records.size(); i++) fout << records[i].nickname << " " << records[i].score << endl;

	fout.close();
}
BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	char str[35];
	int j;
	int x = 0;

	switch (msg) {
	case WM_INITDIALOG:
		SendMessage(GetDlgItem(hDlg, IDC_EDIT1), EM_LIMITTEXT, 30, 0);
		return TRUE;

	case WM_COMMAND:
		switch (wParam) {
		case IDOK:
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), str, 30);
			/*if (strlen(str) == 0) break;
			j = strspn(str, " ");
			if (j != strlen(str)) {
				MessageBox(NULL, "Incorrect nickname", "Error", MB_OK);
				break;
			}*/
			record.nickname = str;
			record.score = (setsnum / Time.count()) * 1000;
			setsnum = 0;
			records.push_back(record);
			sortRecord();
			saveRecord();

			EndDialog(hDlg, 0);
			break;

		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}

		return TRUE;

	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}

void drawField() {
	gameCardsDrawFunc(11, textures[30]);
	static chrono::system_clock::time_point tp1;
	static bool x = 0;
	staticMenuFunc();
	buttonsMenuEnableFunc();
	if (x == 0)
		tp1 = chrono::system_clock::now();

	if (setsnum != 10) {
		if (gamestart == 1) {
			if (xmousepos < 280 && (ymousepos < 480 && ymousepos > 360))
				drawText((char*)"Hint", 140, 428, 255, 0, 0);
			else
				drawText((char*)"Hint", 140, 428, 255, 255, 255);
			x = 1;
			cardsOnFieldStartFunc();
			dynamicGameFunc();

			auto tp2 = chrono::system_clock::now();
			if (setsnum != 10)
				Time = tp2 - tp1;
			else {
				tp1 = chrono::system_clock::now();
			}

			drawText((char*)("Time: " + r((int)Time.count())).c_str(), 140, 188, 255, 255, 255);
			drawText((char*)("Sets num: " + to_string(setsnum)).c_str(), 140, 168, 255, 255, 255);
			drawText((char*)("Score: " + to_string(score)).c_str(), 140, 148, 255, 255, 255);
			for (int i = 0; i < 12; i++)
				if (cardsOnField[i].id != -1)
					gameCardsDrawFunc(i, textures[cardsOnField[i].id]);

			int j = 0;
			for (int i = 0; i < 81; i++) {
				if (cards[i].state == 1) {
					cardsOnField[j] = cards[i];
					j++;
				}
			}
			j = 0;

			if (!notcontoneset) {
				if (isOneSetOnField() == 1)
					cout << "\nSet nums: " << isOneSetCardNum[0] + 1 << " " << isOneSetCardNum[1] + 1 << " " << isOneSetCardNum[2] + 1 << endl;
				else
					redraw();
				notcontoneset = 1;
			}

			/*if (xmousepos < 280 && (ymousepos < 480 && ymousepos > 360) && mousebuttonstate == 1 && helpercont == 0) {
				
					helper();
			}*/
		}

		if (setsnum == 10) {
			DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
			tp1 = chrono::system_clock::now();
			score = 0;
		}
	}
	if (recordmenu == 1) {
		ShellExecute(NULL, "open", "D:\\MSVS Projects\\winopengl\\winopengl\\records.txt", NULL, NULL, SW_NORMAL);
		mousebuttonstate = 0;
		recordmenu = 0;
	}
	if (exitbuttonstate == 1)
		exit(0);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
	glutPostRedisplay();
	glFinish();
}

void staticMenuFunc() {
	GLint color1 = 1;

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(91, 94, 92);
	glBegin(GL_QUADS);

	glVertex2f(0.0, 0.0);
	glVertex2f(280.0, 0.0);
	glVertex2f(280.0, 720.0);
	glVertex2f(0.0, 720.0);

	glEnd();

	glColor3ub(color1, color1, color1);
	glBegin(GL_LINES);

	glVertex2f(280, 0); glVertex2f(280, 720);
	glVertex2f(0, 80);  glVertex2f(280, 80);
	glVertex2f(0, 240); glVertex2f(280, 240);
	glVertex2f(0, 360); glVertex2f(280, 360);
	glVertex2f(0, 480); glVertex2f(280, 480);
	glVertex2f(0, 600); glVertex2f(280, 600);

	glEnd();

	drawText((char*)"Set Classic", 140, 658, 255, 255, 255);
	drawText((char*)"Start game", 140, 548, 255, 255, 255);
	if (gamestart == 0)
		drawText((char*)"Records", 140, 428, 255, 255, 255);
	drawText((char*)"Exit", 140, 308, 255, 255, 255);
	drawText((char*)"", 140, 178, 255, 255, 255);
	drawText((char*)"Unknown corp, 2019", 140, 48, 255, 255, 255);

	int i = 0;

	while (i < 12) {
		drawRect(rectPos.xpos[i], rectPos.ypos[i], 91, 94, 92);
		i++;
	}
}
void dynamicGameFunc() {
	if (cardpressed >= 3) {
		if (cardpressed == 3)
			if ((cardTaken[0].shape == cardTaken[1].shape && cardTaken[1].shape == cardTaken[2].shape) || (cardTaken[0].shape != cardTaken[1].shape && cardTaken[1].shape != cardTaken[2].shape && cardTaken[0].shape != cardTaken[2].shape)) {
				if ((cardTaken[0].color == cardTaken[1].color && cardTaken[1].color == cardTaken[2].color) || (cardTaken[0].color != cardTaken[1].color && cardTaken[1].color != cardTaken[2].color && cardTaken[0].color != cardTaken[2].color)) {
					if ((cardTaken[0].num == cardTaken[1].num && cardTaken[1].num == cardTaken[2].num) || (cardTaken[0].num != cardTaken[1].num && cardTaken[1].num != cardTaken[2].num && cardTaken[0].num != cardTaken[2].num)) {
						if ((cardTaken[0].shading == cardTaken[1].shading && cardTaken[1].shading == cardTaken[2].shading) || (cardTaken[0].shading != cardTaken[1].shading && cardTaken[1].shading != cardTaken[2].shading && cardTaken[0].shading != cardTaken[2].shading)) {
							
							glEnable(GL_TEXTURE_2D);
							glBindTexture(GL_TEXTURE_2D, isSetTexture);

							glColor3ub(255, 255, 255);
							glBegin(GL_QUAD_STRIP);

							glTexCoord2f(0, 0); glVertex2f((1280 / 2) - 160, (720 / 2) - 120);
							glTexCoord2f(0, 1); glVertex2f((1280 / 2) - 160, (720 / 2) + 120);
							glTexCoord2f(1, 0); glVertex2f((1280 / 2) + 160, (720 / 2) - 120);
							glTexCoord2f(1, 1); glVertex2f((1280 / 2) + 160, (720 / 2) + 120);

							glEnd();
							glDisable(GL_TEXTURE_2D);

							setsnum++;
							notcont = 0;
							score += 500;
							for (int i = 0; i < 12; i++) {
								cardsOnField[i] = { -1 };
							}
							for (int i = 0; i < 81; i++) {
								cards[i].state = 0;
							}
							cardsOnFieldStartFunc();
							notcontoneset = 0;
						}
						else {
							glutSetWindowTitle("It's not set!!!");
						}
					}
				}
			}

		for (int i = 0; i < 12; i++) {
			cardTakenButton[i] = 0;
			drawRect(rectPos.xpos[i], rectPos.ypos[i], 91, 94, 92);
		}
		cardpressed = 0;
		cardTaken[0] = { 0 };
		cardTaken[1] = { 0 };
		cardTaken[2] = { 0 };
	}

	for (int i = 0; i < 12; i++)
		if (cardTakenButton[i] == 1) {
			drawRect(rectPos.xpos[i], rectPos.ypos[i], 25, 255, 25);
		}
		else {
			drawRect(rectPos.xpos[i], rectPos.ypos[i], 91, 94, 92);
		}
}
void buttonsMenuEnableFunc() {
	if (xmousepos < 280 && (ymousepos < 600 && ymousepos > 480) && mousebuttonstate == 1) {
		glColor3ub(51, 54, 52);
		glBegin(GL_QUADS);
		glVertex2f(0, 599);
		glVertex2f(279, 599);
		glVertex2f(279, 479);
		glVertex2f(0, 479);
		glEnd();

		gamestart = 1;
	}
	else if (xmousepos < 280 && (ymousepos < 480 && ymousepos > 360) && mousebuttonstate == 1) {
		glColor3ub(51, 54, 52);
		glBegin(GL_QUADS);
		glVertex2f(0, 479);
		glVertex2f(279, 479);
		glVertex2f(279, 359);
		glVertex2f(0, 359);
		glEnd();

		if (gamestart == 1)
			redraw();
		else
			recordmenu = 1;
	}
	else if (xmousepos < 280 && (ymousepos < 360 && ymousepos > 240) && mousebuttonstate == 1) {
		glColor3ub(51, 54, 52);
		glBegin(GL_QUADS);
		glVertex2f(0, 360);
		glVertex2f(280, 360);
		glVertex2f(280, 240);
		glVertex2f(0, 240);
		glEnd();

		exitbuttonstate = 1;
	}

	if (xmousepos < 280 && (ymousepos < 600 && ymousepos > 480))
		drawText((char*)"Start game", 140, 548, 255, 0, 0);
	else
		drawText((char*)"Start game", 140, 548, 255, 255, 255);
	if (xmousepos < 280 && (ymousepos < 360 && ymousepos > 240))
		drawText((char*)"Exit", 140, 308, 255, 0, 0);
	else
		drawText((char*)"Exit", 140, 308, 255, 255, 255);

	if (gamestart == 1) {
		if (xmousepos < 280 && (ymousepos < 480 && ymousepos > 360))
			drawText((char*)"Update", 140, 428, 255, 0, 0);
		else
			drawText((char*)"Update", 140, 428, 255, 255, 255);
	}
	else {
		if (xmousepos < 280 && (ymousepos < 480 && ymousepos > 360))
			drawText((char*)"Records", 140, 428, 255, 0, 0);
		else
			drawText((char*)"Records", 140, 428, 255, 255, 255);
	}
}
void cardsOnFieldStartFunc() {
	int cardnum, i = 0;

	cardnum = rand() % 81;
	if (!notcont) {
		for (int i = 0; i < 12; i++) {
			if (cards[cardnum].state == 0) {
				cards[cardnum].state = 1;
				cardsOnField[i].id = cardnum;
			}
			else {
				cardnum = rand() % 81;
				i--;
			}
		}
	}
	notcont = 1;
}
void redraw() {
	cardpressed = 0;
	cardTaken[0] = { 0 };
	cardTaken[1] = { 0 };
	cardTaken[2] = { 0 };

	notcont = 0;
	for (int i = 0; i < 12; i++) {
		cardsOnField[i] = { -1 };
	}
	for (int i = 0; i < 81; i++) {
		cards[i].state = 0;
	}
	cardsOnFieldStartFunc();
	notcontoneset = 0;
}
int isOneSetOnField() {
	bool setOnField = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (j == i) 
				continue;
			else
				for (int k = 0; k < 12; k++)
					if (k == j || k == i) 
						continue;
					else {
						if ((cardsOnField[i].shape == cardsOnField[j].shape && cardsOnField[j].shape == cardsOnField[k].shape) || (cardsOnField[i].shape != cardsOnField[j].shape && cardsOnField[j].shape != cardsOnField[k].shape && cardsOnField[i].shape != cardsOnField[k].shape)) {
							if ((cardsOnField[i].color == cardsOnField[j].color && cardsOnField[j].color == cardsOnField[k].color) || (cardsOnField[i].color != cardsOnField[j].color && cardsOnField[j].color != cardsOnField[k].color && cardsOnField[i].color != cardsOnField[k].color)) {
								if ((cardsOnField[i].num == cardsOnField[j].num && cardsOnField[j].num == cardsOnField[k].num) || (cardsOnField[i].num != cardsOnField[j].num && cardsOnField[j].num != cardsOnField[k].num && cardsOnField[i].num != cardsOnField[k].num)) {
									if ((cardsOnField[i].shading == cardsOnField[j].shading && cardsOnField[j].shading == cardsOnField[k].shading) || (cardsOnField[i].shading != cardsOnField[j].shading && cardsOnField[j].shading != cardsOnField[k].shading && cardsOnField[i].shading != cardsOnField[k].shading)) {
										setOnField = true;
										isOneSetCardNum[0] = i;
										isOneSetCardNum[1] = j;
										isOneSetCardNum[2] = k;

										setCombination[0] = cardsOnField[i];
										setCombination[1] = cardsOnField[j];
										setCombination[2] = cardsOnField[k];
									}
								}
							}
						}
					}

		}
	}

	if (setOnField)
		return 1;
	else
		return 0;
}
int helper() {
	while (helperCounter != 0) {
		if (cardTakenButton[isOneSetCardNum[0]] == 0) {
			cardTakenButton[isOneSetCardNum[0]] = 1;
			cardTaken[cardpressed] = cardsOnField[isOneSetCardNum[0]];
			cardpressed++;
		}
		else if (cardTakenButton[isOneSetCardNum[1]] == 0) {
			cardTakenButton[isOneSetCardNum[1]] = 1;
			cardTaken[cardpressed] = cardsOnField[isOneSetCardNum[1]];
			cardpressed++;
		}
		else {
			cardTakenButton[isOneSetCardNum[2]] = 1;
			cardTaken[cardpressed] = cardsOnField[isOneSetCardNum[2]];
			cardpressed++;
		}
		helperCounter--;
	}

	if (helperCounter == 0) {
		return 1;
	}
	return 0;
}