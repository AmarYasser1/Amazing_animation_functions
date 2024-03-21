// اللهم صلِ وسلم وبارك علي سيدنا محمد صلي الله عليه وسلم // 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<process.h>
#include<vector>
#include<thread>
#include<chrono>
#include <random>
#include <ctime>
#include<queue>
#define endl '\n';
#define DEBUG
#ifdef DEBUG

#define AmarYasserDebug(condition, message) \
    if (!(condition)) { \
        cerr << "Assertion failed: " << #condition << ". " << message << " [" << __FILE__ << ":" << __LINE__ << "]" << endl; \
        terminate(); \
    }

#else
#define Amar(condition, message)
#endif
using namespace std;
void hideCursor() { cout << "\033[?25l"; }
void showCursor() { cout << "\033[?25h"; }
void clearScreen() { cout << "\033[2J"; }
void clearLine() { cout << "\033[0K\r"; }
void Bold_and_underline_txt() { cout << "\033[1;4m"; }
void reset_setting_default() { cout << "\033[0m"; }
void move_cursor_row_colmn() { cout << "\033[10;20H"; /* Move the cursor 10 row && 20 colmn*/ }
void display_loading_animation() {
	cout << "Loading: ";
	for (int i = 0; i < 30; ++i) {
		cout << "\033[44m "; // Blue background
		cout << "\033[0m";   // Reset attributes
		cout << "\033[46m "; // Cyan background
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	cout << '\n' << endl;

	cout << "\033[0m"; // To reset the default color again .
}
void display_rotation_line_animation() {
	for (int i = 0; i < 10; ++i) {
		cout << "-";
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\b";
		cout << "\\";
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\b";
		cout << "|";
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\b";
		cout << "/";
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\b";
	}
	cout << '\n' << endl;
}
void Another_display_rotation_line_animation_loading() {
	const int numFrames = 4;
	const char frames[numFrames] = { '|', '/', '-', '\\' };

	int frameIndex = 0; 

	int cnt = 0;
	while (cnt++ <= 20) {
		cout << "\033[2J";

		cout << "\033[" << 12 << ";" << 35 << "H";

		cout << frames[frameIndex] << " Loading...";

		frameIndex = (frameIndex + 1) % numFrames;

		this_thread::sleep_for(chrono::milliseconds(200));
	}
}
void Loading1() {
	const int width = 40;

	for (int progress = 0; progress <= width; ++progress) {

		cout << "\033[2J";

		cout << "\033[" << 1 << ";" << 2 << "H";

		cout << "[";

		for (int i = 0; i < width; ++i) {
			if (i < progress) {
				cout << "=";
			}
			else if (i == progress) {
				cout << ">";
			}
			else {
				cout << " ";
			}
		}

		cout << "] " << (progress * 100 / width) << "%";

		this_thread::sleep_for(chrono::milliseconds(100));
	}

	cout << '\n' << "Loading complete!" << endl;
}
void Clock_time() {
	while (true) {
		time_t now = time(0);
		tm* ltm = localtime(&now);

		cout << "\033[2J";

		cout << "\033[" << 1 << ";" << 90 << "H";

		cout << "Current Time: ";
		cout << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":";
		cout << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":";
		cout << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec;

		this_thread::sleep_for(chrono::seconds(1));
	}
}
void Nested_loading() {
	const int barWidth = 40;

	while (true) {
		for (int i = 0; i <= barWidth; ++i) {
			float progress = static_cast<float>(i) / barWidth * 100;

			cout << "\r[";
			for (int j = 0; j < barWidth; ++j) {
				if (j < i) cout << "=";
				else cout << " ";
			}
			cout << "] " << static_cast<int>(progress) << "%";
			cout.flush();

			this_thread::sleep_for(chrono::milliseconds(50));
		}
		cout << endl;
	}
}
void Loading2() {
	const int width = 50;

	while (true) {
		for (int i = 0; i <= width; ++i) {
			cout << "[" << string(i, '=') << string(width - i, ' ') << "]" << i * 2 << "%" << "\r";
			cout.flush();
			this_thread::sleep_for(chrono::milliseconds(100));
		}
	}
}
void bouncingBallAnimation() {
	const int screenWidth = 100;
	const int ballSize = 5;
	int ballPosition = 0;
	int direction = 1;

	while (true) {
		cout << "\033[2J";

		cout << "\033[" << 10 << ";" << ballPosition << "H";

		cout << "O";

		ballPosition += direction;
		if (ballPosition >= screenWidth - ballSize || ballPosition <= 0) {
			direction *= -1;
		}

		this_thread::sleep_for(chrono::milliseconds(50));
	}
}
void fireworkAnimation() {
	const int screenWidth = 100;
	const int screenHeight = 30;

	while (true) {
		clearScreen();

		int posX = rand() % screenWidth + 1;
		int posY = rand() % screenHeight + 1;

		cout << "\033[" << posY << ";" << posX << "H";

		cout << "*";

		this_thread::sleep_for(chrono::milliseconds(50));
	}
}
void MatrixRainAnimation() {
	const int screenWidth = 100;
	const int screenHeight = 30;

	while (true) {
		clearScreen();

		char matrixChar = rand() % 26 + 'A';

		int posX = rand() % screenWidth + 1;
		int posY = rand() % screenHeight + 1;
		cout << "\033[" << posY << ";" << posX << "H";

		cout << matrixChar;

		this_thread::sleep_for(chrono::milliseconds(50));
	}
}
void StarfieldAnimation() {
	const int screenWidth = 100;
	const int screenHeight = 30;
	const int numStars = 100;

	struct Star {
		int x, y;
		char symbol;
	};

	vector<Star> stars;

	for (int i = 0; i < numStars; ++i) {
		stars.push_back({ rand() % screenWidth, rand() % screenHeight, '.' });
	}

	while (true) {
		clearScreen();

		for (auto& star : stars) {
			star.y++;
			if (star.y >= screenHeight) {
				star.y = 0;
				star.x = rand() % screenWidth;
			}

			cout << "\033[" << star.y << ";" << star.x << "H";

			cout << star.symbol;
		}

		this_thread::sleep_for(chrono::milliseconds(50));
	}
}
void display_loading_animation2() {
	int dots = 3;
	string animation = "|/-\\";
	int animation_pos = 0;
	int progress = 0;

	while (progress < 100) {
		cout << "\rLoading: ";

		for (int i = 0; i < dots; ++i) {
			cout << (i <= progress / 33 ? "•" : " ");
		}

		cout << animation[animation_pos];
		animation_pos = (animation_pos + 1) % animation.length();

		cout << " " << flush << progress << "%";

		this_thread::sleep_for(chrono::milliseconds(100));
		progress += 5;
	}

	cout << "\r" << std::string(50, ' ') << flush;
	cout << "\rDone!\n";
}
void amazingDisplayText() {
	Bold_and_underline_txt();
	const string Text = "I love programming."
		"Smile! the wrold need your smile >: ";

	for (int i = 0; i < Text.length(); ++i) {
		cout << '\r' << Text.substr(0, i) << flush;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	cout << "\033[0m";
}

auto main(int argc, char const* argv[]) -> decltype(0)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin.exceptions(ios::badbit | ios::failbit);

	amazingDisplayText();

	// Something of laugh (^_^)
	srand(time(NULL));
	int random1 = rand() % 10;
	int random2 = rand() % 10;

	AmarYasserDebug(random1 == random2, "(Not equal.)");
	return 0;
}