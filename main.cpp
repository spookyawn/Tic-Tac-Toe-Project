#include "TicTacToe.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	TicTacToe::TicTacToe^ tic_tac_toe = gcnew TicTacToe::TicTacToe();
	Application::Run(tic_tac_toe);   
 
}
