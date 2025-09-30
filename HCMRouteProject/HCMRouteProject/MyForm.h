#pragma once
#include "Graph.h"
namespace HCMRouteProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Graph* graph;   // con trỏ native


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			graph = new Graph(3);  // 👈 truyền đúng số đỉnh

			graph->addEdge(0, 1, 4);
			graph->addEdge(1, 2, 2);
			graph->addEdge(0, 2, 5);

			for each(System::String ^ name in gcnew cli::array<System::String^>{"A", "B", "C"}) {
				comboBox1->Items->Add(name);
				comboBox2->Items->Add(name);
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			if (graph) delete graph;   // dọn dẹp native object
		}

	protected:
	private: System::Windows::Forms::Panel^ panel1;


	private: System::Windows::Forms::Panel^ panel2;




	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel9;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel9);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Location = System::Drawing::Point(292, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(965, 664);
			this->panel1->TabIndex = 0;
			// 
			// panel9
			// 
			this->panel9->AutoScroll = true;
			this->panel9->Controls->Add(this->pictureBox2);
			this->panel9->Location = System::Drawing::Point(6, 86);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(959, 578);
			this->panel9->TabIndex = 5;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(46, 60);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1683, 834);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseDown);
			this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox2_MouseEnter);
			this->pictureBox2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseMove);
			this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseUp);
			this->pictureBox2->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseWheel);

			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label3);
			this->panel4->Location = System::Drawing::Point(3, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(959, 89);
			this->panel4->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(954, 83);
			this->label3->TabIndex = 3;
			this->label3->Text = L"PROGRAM TO FIND ROUTES \r\nBETWEEN MAJOR LOCATIONS IN HO CHI MINH CITY";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel8);
			this->panel2->Controls->Add(this->panel7);
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(297, 664);
			this->panel2->TabIndex = 0;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->label4);
			this->panel8->Location = System::Drawing::Point(4, 388);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(293, 126);
			this->panel8->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(-1, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(294, 57);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Result";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->button1);
			this->panel7->Location = System::Drawing::Point(4, 330);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(290, 55);
			this->panel7->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(287, 52);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Find";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->label2);
			this->panel6->Controls->Add(this->comboBox2);
			this->panel6->Location = System::Drawing::Point(4, 244);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(294, 80);
			this->panel6->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(287, 49);
			this->label2->TabIndex = 2;
			this->label2->Text = L"DESTINATION";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(-3, 52);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(297, 28);
			this->comboBox2->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label1);
			this->panel5->Controls->Add(this->comboBox1);
			this->panel5->Location = System::Drawing::Point(3, 158);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(294, 80);
			this->panel5->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(-3, -3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 52);
			this->label1->TabIndex = 2;
			this->label1->Text = L"DEPARTURE";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(-3, 52);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(297, 28);
			this->comboBox1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(0, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(297, 149);
			this->panel3->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1258, 664);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel1->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void pictureBox2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			auto current = gcnew System::Tuple<
				bool, System::Drawing::Point, System::Drawing::Point
			>(true, Cursor->Position, pictureBox2->Location);

			pictureBox2->Tag = current;
		}
	}

	private: System::Void pictureBox2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (pictureBox2->Tag != nullptr) {
			auto state = dynamic_cast<
				System::Tuple<bool, System::Drawing::Point, System::Drawing::Point>^
			>(pictureBox2->Tag);

			if (state != nullptr && state->Item1) {
				System::Drawing::Point diff(
					Cursor->Position.X - state->Item2.X,
					Cursor->Position.Y - state->Item2.Y
				);
				pictureBox2->Location = System::Drawing::Point(
					state->Item3.X + diff.X,
					state->Item3.Y + diff.Y
				);
			}
		}
	}

	private: System::Void pictureBox2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		pictureBox2->Tag = nullptr;
	}
	private: System::Void pictureBox2_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (pictureBox2->Image == nullptr) return;

		// Tỉ lệ zoom (10%)
		float zoomFactor = 1.1f;
		float scale = (e->Delta > 0) ? zoomFactor : 1.0f / zoomFactor;

		// Lấy kích thước hiện tại của pictureBox
		int newWidth = (int)(pictureBox2->Width * scale);
		int newHeight = (int)(pictureBox2->Height * scale);

		// Tính vị trí mới để giữ điểm zoom tại con trỏ
		System::Drawing::Point mousePos = e->Location;
		float relX = (float)mousePos.X / pictureBox2->Width;
		float relY = (float)mousePos.Y / pictureBox2->Height;

		int newX = pictureBox2->Left - (int)(relX * (newWidth - pictureBox2->Width));
		int newY = pictureBox2->Top - (int)(relY * (newHeight - pictureBox2->Height));

		// Giới hạn kích thước tối thiểu / tối đa để tránh zoom quá mức
		if (newWidth < 100 || newHeight < 100) return;
		if (newWidth > 10000 || newHeight > 10000) return;

		pictureBox2->SetBounds(newX, newY, newWidth, newHeight);
	}
private: System::Void pictureBox2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Focus();
}





	};


}
