/***************************************************************
 * Name:      GetReqParserApp.cpp
 * Purpose:   Code for Application Class
 * Author:    z4deepfz ()
 * Created:   2020-08-02
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#include "GetReqParserApp.h"

//(*AppHeaders
#include "GetReqParserMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GetReqParserApp);

bool GetReqParserApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GetReqParserFrame* Frame = new GetReqParserFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
