#pragma once
#include <string>
#include <Windows.h>
#include <vcclr.h>
#include <iostream>
#include <vector>
#include <limits>

namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for TicTacToe
	/// </summary>
	/// 
	///
	
	
	public ref class TicTacToe : public System::Windows::Forms::Form
	{
		const int ROWS = 3;
		const int COLS = 3;
		array<String^, 2>^ arr;   // Declaring as class member variable
		int symbolCounter = 0;
		String^ compSymb = "O";
		String^ userSymb = "X";
		int depthCounter = 0;
		unsigned int score; //-10 is a especial number meaning null
		array<Button^>^ buttons;  // Declaring as class member variable
		int counter = 0;
		

	private: System::Windows::Forms::Label^ turnLbl;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ winnerLbl;

	public:
		TicTacToe(void)
		{
			InitializeComponent();

			// Initialize the 2D array to empty 
			arr = gcnew array<String^, 2>(3, 3);

			// Initialize an array to store the buttons element
			buttons = gcnew array<Button^>(9);
			buttons[0] = button1;
			buttons[1] = button2;
			buttons[2] = button3;
			buttons[3] = button4;
			buttons[4] = button5;
			buttons[5] = button6;
			buttons[6] = button7;
			buttons[7] = button8;
			buttons[8] = button9;

			clearBoard();

			askUser();



		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TicTacToe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ TitleLabel;
	private: System::Windows::Forms::Button^ Exit_btn;
	private: System::Windows::Forms::Button^ button10;
	private: cli::array<cli::array<char>^>^ charArr;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
			this->Exit_btn = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->turnLbl = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->winnerLbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(309, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 162);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TicTacToe::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(494, 88);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(179, 162);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TicTacToe::button2_Click);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Location = System::Drawing::Point(679, 88);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(179, 162);
			this->button3->TabIndex = 2;
			this->button3->Text = L" ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &TicTacToe::button3_Click);
			// 
			// button4
			// 
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(309, 256);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(179, 162);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &TicTacToe::button4_Click);
			// 
			// button5
			// 
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(494, 256);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(179, 162);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &TicTacToe::button5_Click);
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(679, 256);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(179, 162);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &TicTacToe::button6_Click);
			// 
			// button7
			// 
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90));
			this->button7->Location = System::Drawing::Point(309, 424);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(179, 162);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &TicTacToe::button7_Click);
			// 
			// button8
			// 
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90));
			this->button8->Location = System::Drawing::Point(494, 424);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(179, 162);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &TicTacToe::button8_Click);
			// 
			// button9
			// 
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 90));
			this->button9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button9->Location = System::Drawing::Point(679, 424);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(179, 162);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &TicTacToe::button9_Click);
			// 
			// TitleLabel
			// 
			this->TitleLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Pixel", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitleLabel->Location = System::Drawing::Point(12, 23);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(1152, 67);
			this->TitleLabel->TabIndex = 9;
			this->TitleLabel->Text = L"(Imposible) TIC TAC TOE ";
			this->TitleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->TitleLabel->Click += gcnew System::EventHandler(this, &TicTacToe::TitleLabel_Click);
			// 
			// Exit_btn
			// 
			this->Exit_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Exit_btn->Font = (gcnew System::Drawing::Font(L"Pixel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exit_btn->Location = System::Drawing::Point(29, 479);
			this->Exit_btn->Name = L"Exit_btn";
			this->Exit_btn->Size = System::Drawing::Size(161, 63);
			this->Exit_btn->TabIndex = 10;
			this->Exit_btn->Text = L"Exit";
			this->Exit_btn->UseVisualStyleBackColor = true;
			this->Exit_btn->Click += gcnew System::EventHandler(this, &TicTacToe::Exit_btn_Click);
			// 
			// button10
			// 
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->Font = (gcnew System::Drawing::Font(L"Pixel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(29, 403);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(161, 70);
			this->button10->TabIndex = 11;
			this->button10->Text = L"Reset";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &TicTacToe::button10_Click);
			// 
			// turnLbl
			// 
			this->turnLbl->AutoSize = true;
			this->turnLbl->Location = System::Drawing::Point(962, 67);
			this->turnLbl->Name = L"turnLbl";
			this->turnLbl->Size = System::Drawing::Size(114, 31);
			this->turnLbl->TabIndex = 12;
			this->turnLbl->Text = L"X\'s Turn";
			this->turnLbl->Click += gcnew System::EventHandler(this, &TicTacToe::turnLbl_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(962, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 31);
			this->label2->TabIndex = 13;
			// 
			// winnerLbl
			// 
			this->winnerLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winnerLbl->Location = System::Drawing::Point(12, 657);
			this->winnerLbl->Name = L"winnerLbl";
			this->winnerLbl->Size = System::Drawing::Size(1152, 73);
			this->winnerLbl->TabIndex = 14;
			this->winnerLbl->Text = L"Winner Lbl";
			this->winnerLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->winnerLbl->Click += gcnew System::EventHandler(this, &TicTacToe::winnerLbl_Click);
			// 
			// TicTacToe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(1176, 814);
			this->Controls->Add(this->winnerLbl);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->turnLbl);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->Exit_btn);
			this->Controls->Add(this->TitleLabel);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"TicTacToe";
			this->Text = L"TicTacToe";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: Void askUser() {
		// Display a message box to ask the user for their choice
		String^ message = "Do you want to make the first move?";
		String^ caption = "First Move Choice";
		MessageBoxButtons buttons = MessageBoxButtons::YesNo;
		System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(message, caption, buttons, MessageBoxIcon::Question);

		// Depending on the user's choice, set the symbol for the user and the computer
		if (result == System::Windows::Forms::DialogResult::Yes) {
			turnLbl->Text = "You are (X)";
		}
		else {
			turnLbl->Text = "You are (X)";
			makeComputerMove(); // Computer makes the first move
		}
	}



	private: int evaluate(array<String^, 2>^ board) {
		// Check rows for a win
		for (int i = 0; i < ROWS; ++i) {
			if (board[i, 0] == board[i, 1] && board[i, 1] == board[i, 2]) {
				if (board[i, 0] == compSymb)
					return 1;
				else if (board[i, 0] == userSymb)
					return -1;
			}
		}

		// Check columns for a win
		for (int j = 0; j < COLS; ++j) {
			if (board[0, j] == board[1, j] && board[1, j] == board[2, j]) {
				if (board[0, j] == compSymb)
					return 1;
				else if (board[0, j] == userSymb)
					return -1;
			}
		}

		// Check diagonals for a win
		if ((board[0, 0] == board[1, 1] && board[1, 1] == board[2, 2]) ||
			(board[0, 2] == board[1, 1] && board[1, 1] == board[2, 0])) {
			if (board[1, 1] == compSymb)
				return 1;
			else if (board[1, 1] == userSymb)
				return -1;
		}

		// If no winner, check for a tie
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				if (board[i, j] == " ") {
					// Game is not over yet, return 0
					return -10;
				}
			}
		}

		// If no winner and no empty cells, it's a tie
		return 0;
	}


	private: int minimax(array<String^, 2>^ board, int depth, bool isMaximizer) {
		int score = evaluate(board);

		// If the game has ended (either win, loss, or tie), return the score
		if (score != -10) {
			return score;
		}

		// If maximizing player's turn
		if (isMaximizer) {
			int bestScore = Int32::MinValue;
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					if (board[i, j] == " ") {
						// Make a copy of the board
						array<String^, 2>^ newBoard = gcnew array<String^, 2>(3, 3);
						Array::Copy(board, newBoard, board->Length);
						newBoard[i, j] = compSymb;
						int currScore = minimax(newBoard, depth + 1, false);
						bestScore = Math::Max(bestScore, currScore);
					}
				}
			}
			return bestScore;
		}
		// If minimizing player's turn
		else {
			int bestScore = Int32::MaxValue;
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					if (board[i, j] == " ") {
						// Make a copy of the board
						array<String^, 2>^ newBoard = gcnew array<String^, 2>(3, 3);
						Array::Copy(board, newBoard, board->Length);
						newBoard[i, j] = userSymb;
						int currScore = minimax(newBoard, depth + 1, true);
						bestScore = Math::Min(bestScore, currScore);
					}
				}
			}
			return bestScore;
		}
	}



	private: Void makeHumanMove(int buttonIndex) {

		int buttonCounter = 0;
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) { // Corrected the increment from i++ to j++
				if (buttonCounter == buttonIndex) {
					arr[i, j] = userSymb;
					printBoard();
					buttons[buttonIndex]->Enabled = false;
					checkGameStatus();
					return;
				}
				else {
					buttonCounter++;
				}
			}
		}
	}

	private: Void makeComputerMove() {
		int bestScore = Int32::MinValue;
		unsigned int bestRow;
		unsigned int bestCol;
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				if (arr[i, j] == " ") {
					arr[i, j] = compSymb;
					int currScore = minimax(arr, 0, false);
					arr[i, j] = " "; // Restore the board state
					if (currScore > bestScore) {
						bestScore = currScore;
						bestRow = i;
						bestCol = j;
					}
				}
			}
		}
		if (bestRow <= 2 && bestCol <= 2) {
			arr[bestRow, bestCol] = compSymb;
			printBoard();
			buttons[(bestRow * 3) + bestCol]->Enabled = false;
			checkGameStatus();

		}
	}
	

	private: Void printBoard() {
		int counter = 0;
		

		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				buttons[counter]->Text = arr[i, j];
				counter++;
			}
		}
		symbolCounter++;
	}

	private: Void clearBoard() {
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				arr[i, j] = " ";
			}
		}
		enablebuttons(); 
		printBoard();
		//clears winner lbl
		winnerLbl->Text = "";
	}
	private: Void enablebuttons() {
		for (int i = 0; i < 9; ++i) {
			buttons[i]->Enabled = true;
		}
	}
	private:Void unableButtons() {
		for (int i = 0; i < 9; ++i) {
			buttons[i]->Enabled = false;
		}
	}


	private: Void checkGameStatus() {

		int tempScore = evaluate(arr);
		if (tempScore == 1) {
			String^ message = compSymb +" wins the game!, Better Luck Next Time";
			System::Windows::Forms::MessageBox::Show(message, "GameStatus", MessageBoxButtons::OK, MessageBoxIcon::Information);
			unableButtons();
			winnerLbl->Text = compSymb + " is the winner!";
		}
		else if (tempScore == -1) {
			String^ message = userSymb + " wins the game!, How did you did that :o, Congratulations!";
			System::Windows::Forms::MessageBox::Show(message, "GameStatus", MessageBoxButtons::OK, MessageBoxIcon::Information);
			unableButtons();
			winnerLbl->Text = userSymb + " is the winner!";
		}
		else if (tempScore == 0) {
			String^ message = "The game ended in a Tie!, No one wins";
			System::Windows::Forms::MessageBox::Show(message, "GameStatus", MessageBoxButtons::OK, MessageBoxIcon::Information);
			winnerLbl->Text = "The game ended on a tie!";
		}
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Exit_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(0);
	makeComputerMove();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(1);
	makeComputerMove();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(2);
	makeComputerMove();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(3);
	makeComputerMove();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(4);
	makeComputerMove();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(5);
	makeComputerMove();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(6);
	makeComputerMove();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(7);
	makeComputerMove();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	makeHumanMove(8);
	makeComputerMove();
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void turnLbl_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	clearBoard();
	askUser();
}
private: System::Void winnerLbl_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TitleLabel_Click(System::Object^ sender, System::EventArgs^ e) {

	TitleLabel->Text = ("Not (Impossible) Tic Tac Toe");
	
}
};
}
