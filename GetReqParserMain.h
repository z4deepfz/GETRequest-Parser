/***************************************************************
 * Name:      GetReqParserMain.h
 * Purpose:   Defines Application Frame
 * Author:    z4deepfz ()
 * Created:   2020-08-02
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#ifndef GETREQPARSERMAIN_H
#define GETREQPARSERMAIN_H

#include "URLParser.h"

//(*Headers(GetReqParserFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class GetReqParserFrame: public wxFrame
{
    public:

        GetReqParserFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GetReqParserFrame();

    protected:
        URLParser m_parser;
        URLinfo   m_info;

    private:

        //(*Handlers(GetReqParserFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnUserEnterText(wxCommandEvent& event);
        void OnItemChoosed(wxCommandEvent& event);
        void OnDetailChanged(wxCommandEvent& event);
        void OnDeleteItem(wxCommandEvent& event);
        void OnClicpboardCopy(wxCommandEvent& event);
        //*)

        //(*Identifiers(GetReqParserFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON4;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GetReqParserFrame)
        wxButton* btnAutoRmv;
        wxButton* btnCopy;
        wxButton* btnDel;
        wxButton* btnSave;
        wxListBox* itemBox;
        wxPanel* top_panel;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* textKey;
        wxTextCtrl* textURL;
        wxTextCtrl* textValue;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GETREQPARSERMAIN_H
