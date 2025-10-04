#pragma once
#include "Graph.h"
#include <msclr/marshal_cppstd.h>

namespace HCMRouteProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace Microsoft::Web::WebView2::WinForms; // WebView2
	using namespace Microsoft::Web::WebView2::Core;
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
			//graph = new Graph(3);  // 👈 truyền đúng số đỉnh

			//graph->addEdge(0, 1, 4);
			//graph->addEdge(1, 2, 2);
			//graph->addEdge(0, 2, 5);

			//for each(System::String ^ name in gcnew cli::array<System::String^>{"A", "B", "C"}) {
			//	comboBox1->Items->Add(name);
			//	comboBox2->Items->Add(name);
			//}
			graph = new Graph();

			
			
			PopulateComboBoxes();
			LoadHtmlFile();	// nạp file html
			ApplyVirtualHost();
	

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
	private: System::Windows::Forms::Panel^ MainPanel;



	private: System::Windows::Forms::Panel^ LabelContainer;
	private: System::Windows::Forms::Panel^ LogoPanel;






	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ DepartLabel;
	private: System::Windows::Forms::ComboBox^ DepartComboBox;


	private: System::Windows::Forms::Label^ LabelMain;


	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ DestLabel;
	private: System::Windows::Forms::ComboBox^ DestComboBox;
	private: System::Windows::Forms::Panel^ ResultContainer;




	private: System::Windows::Forms::Label^ ResultLabel;

	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ FindButton;

	private: System::Windows::Forms::Panel^ panel9;


	private: Microsoft::Web::WebView2::WinForms::WebView2^ Map;





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
			this->Map = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
			this->LabelContainer = (gcnew System::Windows::Forms::Panel());
			this->LabelMain = (gcnew System::Windows::Forms::Label());
			this->MainPanel = (gcnew System::Windows::Forms::Panel());
			this->ResultContainer = (gcnew System::Windows::Forms::Panel());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->DestLabel = (gcnew System::Windows::Forms::Label());
			this->DestComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->DepartLabel = (gcnew System::Windows::Forms::Label());
			this->DepartComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->LogoPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map))->BeginInit();
			this->LabelContainer->SuspendLayout();
			this->MainPanel->SuspendLayout();
			this->ResultContainer->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel9);
			this->panel1->Controls->Add(this->LabelContainer);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1258, 664);
			this->panel1->TabIndex = 0;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel9->AutoScroll = true;
			this->panel9->AutoSize = true;
			this->panel9->Controls->Add(this->Map);
			this->panel9->Location = System::Drawing::Point(297, 73);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(973, 663);
			this->panel9->TabIndex = 5;
			// 
			// Map
			// 
			this->Map->AllowExternalDrop = true;
			this->Map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Map->CreationProperties = nullptr;
			this->Map->DefaultBackgroundColor = System::Drawing::Color::White;
			this->Map->Location = System::Drawing::Point(2, 3);
			this->Map->Name = L"Map";
			this->Map->Size = System::Drawing::Size(959, 628);
			this->Map->TabIndex = 1;
			this->Map->ZoomFactor = 1;
			// 
			// LabelContainer
			// 
			this->LabelContainer->Controls->Add(this->LabelMain);
			this->LabelContainer->Dock = System::Windows::Forms::DockStyle::Top;
			this->LabelContainer->Location = System::Drawing::Point(0, 0);
			this->LabelContainer->Name = L"LabelContainer";
			this->LabelContainer->Size = System::Drawing::Size(1258, 89);
			this->LabelContainer->TabIndex = 3;
			// 
			// LabelMain
			// 
			this->LabelMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->LabelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LabelMain->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelMain->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->LabelMain->Location = System::Drawing::Point(0, 0);
			this->LabelMain->Name = L"LabelMain";
			this->LabelMain->Padding = System::Windows::Forms::Padding(230, 0, 0, 15);
			this->LabelMain->Size = System::Drawing::Size(1258, 89);
			this->LabelMain->TabIndex = 3;
			this->LabelMain->Text = L"PROGRAM TO FIND ROUTES \r\nBETWEEN MAJOR LOCATIONS IN HO CHI MINH CITY";
			this->LabelMain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MainPanel
			// 
			this->MainPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->MainPanel->Controls->Add(this->ResultContainer);
			this->MainPanel->Controls->Add(this->panel7);
			this->MainPanel->Controls->Add(this->panel6);
			this->MainPanel->Controls->Add(this->panel5);
			this->MainPanel->Controls->Add(this->LogoPanel);
			this->MainPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->MainPanel->Location = System::Drawing::Point(0, 0);
			this->MainPanel->Name = L"MainPanel";
			this->MainPanel->Size = System::Drawing::Size(297, 664);
			this->MainPanel->TabIndex = 0;
			// 
			// ResultContainer
			// 
			this->ResultContainer->Controls->Add(this->ResultLabel);
			this->ResultContainer->Location = System::Drawing::Point(4, 388);
			this->ResultContainer->Name = L"ResultContainer";
			this->ResultContainer->Size = System::Drawing::Size(293, 63);
			this->ResultContainer->TabIndex = 8;
			// 
			// ResultLabel
			// 
			this->ResultLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->ResultLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResultLabel->ForeColor = System::Drawing::Color::Black;
			this->ResultLabel->Location = System::Drawing::Point(-1, 0);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(294, 57);
			this->ResultLabel->TabIndex = 3;
			this->ResultLabel->Text = L"Result";
			this->ResultLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->FindButton);
			this->panel7->Location = System::Drawing::Point(4, 330);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(290, 55);
			this->panel7->TabIndex = 7;
			// 
			// FindButton
			// 
			this->FindButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->FindButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FindButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FindButton->Location = System::Drawing::Point(-6, 6);
			this->FindButton->Margin = System::Windows::Forms::Padding(0);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(307, 52);
			this->FindButton->TabIndex = 6;
			this->FindButton->Text = L"Find";
			this->FindButton->UseVisualStyleBackColor = false;
			this->FindButton->Click += gcnew System::EventHandler(this, &MyForm::FindButton_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->DestLabel);
			this->panel6->Controls->Add(this->DestComboBox);
			this->panel6->Location = System::Drawing::Point(4, 244);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(294, 80);
			this->panel6->TabIndex = 5;
			// 
			// DestLabel
			// 
			this->DestLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DestLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->DestLabel->Location = System::Drawing::Point(4, 0);
			this->DestLabel->Name = L"DestLabel";
			this->DestLabel->Size = System::Drawing::Size(287, 49);
			this->DestLabel->TabIndex = 2;
			this->DestLabel->Text = L"DESTINATION";
			this->DestLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DestComboBox
			// 
			this->DestComboBox->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DestComboBox->FormattingEnabled = true;
			this->DestComboBox->Location = System::Drawing::Point(-1, 52);
			this->DestComboBox->Name = L"DestComboBox";
			this->DestComboBox->Size = System::Drawing::Size(297, 32);
			this->DestComboBox->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->DepartLabel);
			this->panel5->Controls->Add(this->DepartComboBox);
			this->panel5->Location = System::Drawing::Point(3, 158);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(294, 80);
			this->panel5->TabIndex = 4;
			// 
			// DepartLabel
			// 
			this->DepartLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->DepartLabel->Location = System::Drawing::Point(-3, -3);
			this->DepartLabel->Name = L"DepartLabel";
			this->DepartLabel->Size = System::Drawing::Size(294, 52);
			this->DepartLabel->TabIndex = 2;
			this->DepartLabel->Text = L"DEPARTURE";
			this->DepartLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DepartComboBox
			// 
			this->DepartComboBox->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartComboBox->FormattingEnabled = true;
			this->DepartComboBox->Location = System::Drawing::Point(-3, 52);
			this->DepartComboBox->Name = L"DepartComboBox";
			this->DepartComboBox->Size = System::Drawing::Size(297, 32);
			this->DepartComboBox->TabIndex = 0;
			// 
			// LogoPanel
			// 
			this->LogoPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->LogoPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoPanel.BackgroundImage")));
			this->LogoPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LogoPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->LogoPanel->Location = System::Drawing::Point(0, 0);
			this->LogoPanel->Margin = System::Windows::Forms::Padding(0);
			this->LogoPanel->Name = L"LogoPanel";
			this->LogoPanel->Size = System::Drawing::Size(298, 155);
			this->LogoPanel->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1258, 664);
			this->Controls->Add(this->MainPanel);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"FindRouteHCM";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map))->EndInit();
			this->LabelContainer->ResumeLayout(false);
			this->MainPanel->ResumeLayout(false);
			this->ResultContainer->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		



		void LoadHtmlFile()			// nạp file html từ thư mục hiện hành
		{
			String^ htmlPath = Path::Combine(Directory::GetCurrentDirectory(), "aaa.html");
			Uri^ uri = gcnew Uri("file:///" + htmlPath);
			Map->Source = uri;
			if (Map->CoreWebView2 == nullptr)
			{
				MessageBox::Show("Loading...");
				return;
			}
			Console::WriteLine("Loading HTML file from: " + htmlPath);
		}
		void ApplyVirtualHost()			// ánh xạ thư mục hiện hành thành virtual host
		{
		

			String^ folderPath = Directory::GetCurrentDirectory();
			Map->CoreWebView2->SetVirtualHostNameToFolderMapping(
				"local.map", folderPath,
				CoreWebView2HostResourceAccessKind::Allow
			);

			Map->Source = gcnew Uri("https://local.map/aaa.html");
			Console::WriteLine("Đã nạp HTML qua virtual host: " + folderPath);
			Map->CoreWebView2->WebMessageReceived +=
				gcnew EventHandler<CoreWebView2WebMessageReceivedEventArgs^>(this, &MyForm::OnWebMessageReceived);

		}

	

		void PopulateGraphFromJson(String^ json) {
			graph->clear(); // Nếu bạn có hàm clear()

			array<String^>^ entries = json->Split(gcnew array<wchar_t>{ '{' }, StringSplitOptions::RemoveEmptyEntries);
			for each (String ^ entry in entries) {
				if (!entry->Contains("id")) continue;

				int id = ExtractInt(entry, "\"id\":");
				String^ name = ExtractString(entry, "\"name\":\"");
				double lat = ExtractDouble(entry, "\"lat\":");
				double lng = ExtractDouble(entry, "\"lng\":");

				graph->addNode(id, msclr::interop::marshal_as<std::string>(name), lat, lng);
			}
		}
		
		int ExtractInt(String^ src, String^ key) {	// trích xuất giá trị int từ chuỗi JSON
			int start = src->IndexOf(key);
			if (start < 0) return -1;
			start += key->Length;
			int end = src->IndexOfAny(gcnew array<wchar_t>{ ',', '}' }, start);
			String^ val = src->Substring(start, end - start);
			return Convert::ToInt32(val->Trim());
		}

		double ExtractDouble(String^ src, String^ key) {
			int start = src->IndexOf(key);
			if (start < 0) return 0;
			start += key->Length;
			int end = src->IndexOfAny(gcnew array<wchar_t>{ ',', '}' }, start);
			String^ val = src->Substring(start, end - start);
			return Convert::ToDouble(val->Trim());
		}

		String^ ExtractString(String^ src, String^ key) {
			int start = src->IndexOf(key);
			if (start < 0) return "";
			start += key->Length;
			int end = src->IndexOf('"', start);
			return src->Substring(start, end - start);
		}
		void PopulateComboBoxes() {
			DepartComboBox->Items->Clear();
			DestComboBox->Items->Clear();

			for each (auto pair in graph->getAllNodes()) {
				int id = pair.first;
				Node node = pair.second;
				String^ display = id.ToString() + " - " + gcnew String(node.name.c_str());
				DepartComboBox->Items->Add(display);
				DestComboBox->Items->Add(display);
			}
			MessageBox::Show("Số lượng node: " + graph->getAllNodes().size().ToString());
			MessageBox::Show("Số lượng cạnh: " + graph->getAllEdges().size().ToString());



		}

		String^ FindComboItemById(int id) {
			for each (String ^ item in DepartComboBox->Items) {
				if (item->StartsWith(id.ToString() + " ")) return item;
			}
			return nullptr;
		}
		void OnWebMessageReceived(Object^ sender, CoreWebView2WebMessageReceivedEventArgs^ e) {
			String^ msg = gcnew String(e->TryGetWebMessageAsString());

			if (msg->StartsWith("nodeList:")) {
				String^ json = msg->Substring(9); // Bỏ "nodeList:"
				PopulateGraphFromJson(json);
				PopulateComboBoxes();
			}
			else if (msg->StartsWith("nodeClick:")) {
				String^ idStr = msg->Substring(10);
				int nodeId = Convert::ToInt32(idStr);
				DepartComboBox->SelectedItem = FindComboItemById(nodeId);
			}
		}

		void FindButton_Click(Object^ sender, EventArgs^ e) {				// xử lý sự kiện nút Find
			if (!graph) return;

			String^ startStr = DepartComboBox->SelectedItem->ToString();
			String^ endStr = DestComboBox->SelectedItem->ToString();

			int startId = Convert::ToInt32(startStr->Split('-')[0]->Trim());
			int endId = Convert::ToInt32(endStr->Split('-')[0]->Trim());

			auto path = graph->dijkstra(startId, endId);
			if (path.empty()) {
				ResultLabel->Text = "Không tìm thấy đường đi.";
				return;
			}

			// Hiển thị kết quả
			System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
			for (int id : path) {
				Node node = graph->getNode(id);
				sb->Append(gcnew String(node.name.c_str()));
				sb->Append(" → ");
			}
			ResultLabel->Text = sb->ToString();

			// Tạo JSON gửi sang WebView2
			System::Text::StringBuilder^ js = gcnew System::Text::StringBuilder();
			js->Append("drawPath([");
			for (int id : path) {
				Node node = graph->getNode(id);
				js->Append("{lat:");
				js->Append(node.lat.ToString("F6"));
				js->Append(",lng:");
				js->Append(node.lng.ToString("F6"));
				js->Append("},");
			}
			js->Append("])");

			Map->ExecuteScriptAsync(js->ToString());
		}

		







};


}
