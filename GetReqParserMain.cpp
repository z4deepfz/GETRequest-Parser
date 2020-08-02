/***************************************************************
 * Name:      GetReqParserMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    z4deepfz ()
 * Created:   2020-08-02
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#include "GetReqParserMain.h"
#include <wx/msgdlg.h>
#include <wx/clipbrd.h>

//(*InternalHeaders(GetReqParserFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GetReqParserFrame)
const long GetReqParserFrame::ID_STATICTEXT1 = wxNewId();
const long GetReqParserFrame::ID_TEXTCTRL1 = wxNewId();
const long GetReqParserFrame::ID_BUTTON4 = wxNewId();
const long GetReqParserFrame::ID_LISTBOX1 = wxNewId();
const long GetReqParserFrame::ID_BUTTON3 = wxNewId();
const long GetReqParserFrame::ID_STATICTEXT2 = wxNewId();
const long GetReqParserFrame::ID_TEXTCTRL2 = wxNewId();
const long GetReqParserFrame::ID_STATICTEXT3 = wxNewId();
const long GetReqParserFrame::ID_TEXTCTRL3 = wxNewId();
const long GetReqParserFrame::ID_BUTTON1 = wxNewId();
const long GetReqParserFrame::ID_BUTTON2 = wxNewId();
const long GetReqParserFrame::ID_PANEL1 = wxNewId();
const long GetReqParserFrame::idMenuQuit = wxNewId();
const long GetReqParserFrame::idMenuAbout = wxNewId();
const long GetReqParserFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GetReqParserFrame,wxFrame)
    //(*EventTable(GetReqParserFrame)
    //*)
END_EVENT_TABLE()

GetReqParserFrame::GetReqParserFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GetReqParserFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* GETSizer;
    wxBoxSizer* URLSizer;
    wxBoxSizer* top_sizer;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;

    Create(parent, wxID_ANY, _("GET Request Parser"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(640,480));
    top_panel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    top_sizer = new wxBoxSizer(wxVERTICAL);
    URLSizer = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(top_panel, ID_STATICTEXT1, _("URL"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    URLSizer->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    textURL = new wxTextCtrl(top_panel, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    URLSizer->Add(textURL, 1, wxALL|wxEXPAND, 5);
    btnCopy = new wxButton(top_panel, ID_BUTTON4, _("Copy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    URLSizer->Add(btnCopy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    top_sizer->Add(URLSizer, 1, wxALL|wxEXPAND, 5);
    GETSizer = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, top_panel, _("Items"));
    itemBox = new wxListBox(top_panel, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_SINGLE|wxLB_HSCROLL|wxLB_SORT|wxTAB_TRAVERSAL|wxVSCROLL, wxDefaultValidator, _T("ID_LISTBOX1"));
    StaticBoxSizer2->Add(itemBox, 1, wxALL|wxEXPAND, 5);
    btnAutoRmv = new wxButton(top_panel, ID_BUTTON3, _("Auto Remove Private Content"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer2->Add(btnAutoRmv, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GETSizer->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, top_panel, _("Details"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(top_panel, ID_STATICTEXT2, _("Key"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
    textKey = new wxTextCtrl(top_panel, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer4->Add(textKey, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(BoxSizer4, 0, wxALL|wxEXPAND, 0);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(top_panel, ID_STATICTEXT3, _("Value"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
    textValue = new wxTextCtrl(top_panel, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer5->Add(textValue, 5, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    btnSave = new wxButton(top_panel, ID_BUTTON1, _("Save Changes"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(btnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnDel = new wxButton(top_panel, ID_BUTTON2, _("Delete Item"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(btnDel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer1, 0, wxALL|wxEXPAND, 0);
    StaticBoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND, 0);
    GETSizer->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    top_sizer->Add(GETSizer, 8, wxALL|wxEXPAND, 5);
    top_panel->SetSizer(top_sizer);
    top_sizer->Fit(top_panel);
    top_sizer->SetSizeHints(top_panel);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&GetReqParserFrame::OnUserEnterText);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GetReqParserFrame::OnClicpboardCopy);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&GetReqParserFrame::OnItemChoosed);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&GetReqParserFrame::OnDetailChanged);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GetReqParserFrame::OnDetailChanged);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GetReqParserFrame::OnDeleteItem);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GetReqParserFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GetReqParserFrame::OnAbout);
    //*)
}

GetReqParserFrame::~GetReqParserFrame()
{
    //(*Destroy(GetReqParserFrame)
    //*)
}

void GetReqParserFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GetReqParserFrame::OnAbout(wxCommandEvent& event)
{
    wxString build_msg = "Build Info: " + wxbuildinfo(long_f);
    wxString author_msg = "Author: z4deepfz\n";
    wxString github_page = "Github: https://github.com/z4deepfz\n";
    wxMessageBox(author_msg+github_page+build_msg, _("About GET Request Parser"));
}




/** 自定义函数部分 **/

void GetReqParserFrame::OnUserEnterText(wxCommandEvent& event)
{
    /// function: when user enter the url, parse it
    /// 1. Check if it is an URL
    //wxMessageBox("1");
    m_parser.SetURL((std::string)textURL->GetValue());
    if( m_parser.IsLegalURL() == false ){
        // if it is an illegal url, stop the process at once
        return;
    }

    /// 2. Parser the URL
    m_info = m_parser.GetParsedURLinfo();

    /// 3. Add the items (proxy, address, port, filepath, request, anchor) into the listbox
    itemBox->Clear();
    for(auto i: m_info.GetReqMap){
        auto ikey = i.first;
        auto ival = i.second;
        itemBox->Append(ikey);
    }

    /// return
    return;
}

void GetReqParserFrame::OnItemChoosed(wxCommandEvent& event)
{
    /// function: when select a item, show the detail on the right 2(or more) boxes
    /// 1. find the item details
    auto sel = (std::string)itemBox->GetString(itemBox->GetSelection());
    auto val = m_info.GetReqMap[sel];

    /// 2. use wxTextCtrl::ChangeValue() to fill the box ( warning: dont use SetValue() )
    textKey->ChangeValue(sel);
    textValue->ChangeValue(val);

    /// return
    return;
}

void GetReqParserFrame::OnDetailChanged(wxCommandEvent& event)
{
    /// function: when user change the string of key and value, change the URL string at once
    /// 1. get selection
    auto sel = itemBox->GetSelection();
    if(sel == wxNOT_FOUND){
        return; // if nothing selected, return at once
    }

    /// 2. find the value in map and change it
    auto s = (std::string)itemBox->GetString(sel);
    m_info.GetReqMap[s] = textValue->GetValue();

    /// 3. send new URLinfo to URLParser via `URLParser::SetURL()`
    m_parser.SetURL(m_info);

    /// 4. set the new value to url text
    textURL->SetValue(m_parser.GetURL());

    /// return
    return;
}

void GetReqParserFrame::OnDeleteItem(wxCommandEvent& event)
{
    /// function: delete current item
    /// 1. get selection
    auto sel = itemBox->GetSelection();
    if(sel == wxNOT_FOUND){
        return; // if nothing selected, return at once
    }

    /// 2. find the value in map
    auto s = (std::string)itemBox->GetString(sel);
    m_info.GetReqMap.erase(s);

    /// 3. send newer URLinfo to URLParser to update
    m_parser.SetURL(m_info);
    textURL->SetValue(m_parser.GetURL());

}

void GetReqParserFrame::OnClicpboardCopy(wxCommandEvent& event)
{
    /// function: copy the text from urltext to clipboard
    if(wxTheClipboard->Open()){
        wxTheClipboard->SetData(new wxTextDataObject(textURL->GetValue()));
        wxTheClipboard->Close();
    }
}
