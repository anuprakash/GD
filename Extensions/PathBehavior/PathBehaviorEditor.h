/**

GDevelop - Path Behavior Extension
Copyright (c) 2010-2016 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/

#if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
#ifndef PHYSICSBEHAVIOREDITOR_H
#define PHYSICSBEHAVIOREDITOR_H

#include <vector>
#include <map>
#include <string>
#include "GDCore/String.h"
#include <SFML/System/Vector2.hpp>

//(*Headers(PathBehaviorEditor)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/tglbtn.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <wx/menu.h>
#include <memory>
namespace gd { class Project; }
namespace gd { class MainFrameWrapper; }
class PathBehavior;
namespace gd { class Layout; }
class ScenePathDatas;

///Class storing datas about a path for the editor (only used by the editor, not by the runtime game).
struct PathInfo
{
    gd::String name; ///< Path's name
    std::vector<sf::Vector2f> path; ///< Path's points
    bool isGlobal; ///< Is this a global path ?
};

class PathBehaviorEditor: public wxDialog
{
	public:

		PathBehaviorEditor(wxWindow* parent, gd::Project & game_, gd::Layout * scene, PathBehavior & behavior_, gd::MainFrameWrapper & mainFrameWrapper_ );
		virtual ~PathBehaviorEditor();

		//(*Declarations(PathBehaviorEditor)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxSpinCtrl* bgImgYSpin;
		wxBitmapButton* BitmapButton5;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxCheckBox* globalCheck;
		wxSpinCtrl* bgImgXSpin;
		wxStaticText* contextMessageLabel;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxTextCtrl* speedEdit;
		wxToggleButton* ToggleButton1;
		wxTextCtrl* yOffsetEdit;
		wxBitmapButton* BitmapButton2;
		wxStaticText* StaticText1;
		wxTextCtrl* angleOffsetEdit;
		wxStaticText* StaticText3;
		wxButton* cancelBt;
		wxBitmapButton* BitmapButton1;
		wxCheckBox* stopCheck;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxMenu pointMenu;
		wxMenu advanceAddMenu;
		wxBitmapButton* BitmapButton6;
		wxStaticLine* StaticLine1;
		wxBitmapButton* BitmapButton4;
		wxBitmapButton* BitmapButton3;
		wxCheckBox* reverseCheck;
		wxPanel* previewPnl;
		wxStaticText* StaticText4;
		wxChoice* pathChoice;
		wxButton* okBt;
		wxCheckBox* followAngleCheck;
		wxTextCtrl* xOffsetEdit;
		//*)

		PathBehavior & behavior;

	protected:

		//(*Identifiers(PathBehaviorEditor)
		static const long ID_STATICTEXT6;
		static const long ID_CHOICE1;
		static const long ID_BITMAPBUTTON3;
		static const long ID_BITMAPBUTTON4;
		static const long ID_BITMAPBUTTON5;
		static const long ID_CHECKBOX4;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON6;
		static const long ID_BITMAPBUTTON2;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT1;
		static const long ID_PANEL1;
		static const long ID_TOGGLEBUTTON1;
		static const long ID_STATICTEXT11;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT12;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL4;
		static const long ID_CHECKBOX3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT10;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)
        //Contextual menu
		static const long coordsBtID;
		static const long positionBtID;
		static const long addPointAfterBtID;
		static const long removePointBtID;
        //Avanced Add Menu
		static const long addAfterBtID;
		static const long addBeforeBtID;

	private:

		//(*Handlers(PathBehaviorEditor)
		void OncancelBtClick(wxCommandEvent& event);
		void OnokBtClick(wxCommandEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnpreviewPnlLeftDown(wxMouseEvent& event);
		void OnpreviewPnlLeftUp(wxMouseEvent& event);
		void OnpreviewPnlMouseMove(wxMouseEvent& event);
		void OnBitmapButton1Click(wxCommandEvent& event);
		void OnBitmapButton2Click(wxCommandEvent& event);
		void OnBitmapButton3Click(wxCommandEvent& event);
		void OnpreviewPnlRightUp(wxMouseEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnpathChoiceSelect(wxCommandEvent& event);
		void OnBitmapButton3Click1(wxCommandEvent& event);
		void OnBitmapButton4Click(wxCommandEvent& event);
		void OnglobalCheckClick(wxCommandEvent& event);
		void OnBitmapButton5Click(wxCommandEvent& event);
		void OnBitmapButton6Click(wxCommandEvent& event);
		void OnbgImgXSpinChange(wxSpinEvent& event);
		void OnpreviewPnlEraseBackground(wxEraseEvent& event);
		void OnBitmapButton6Click1(wxCommandEvent& event);
		//*)

		int GetPointOnMouse(wxMouseEvent& event);
		int GetSegmentOnMouse(wxMouseEvent& event);

		void UpdateContextMessage();
		void UpdateComboBoxWithPathsName();

		void ChangePathOfPreview(const gd::String &name);
		bool PathExists(const gd::String &name);

		gd::String GetNameWithoutPrefix(gd::String name);

		gd::Project & game;
        gd::Layout * scene;
        std::shared_ptr<ScenePathDatas> sharedDatas;
		gd::MainFrameWrapper & mainFrameWrapper;

        PathInfo *pathInfo;
		std::vector<sf::Vector2f> *path; ///< Pointer to the path edited, making it more easy and fast to be accessed
		std::map<gd::String, PathInfo> paths; ///< Contains all paths.
		gd::String currentPathName; ///< Contain the name of the current path

        //Contextual menu
		wxMenuItem *coordsBt;
		wxMenuItem *positionBt;
        wxMenuItem *addPointAfterBt;
        wxMenuItem *removePointBt;

        //Avanced Add Menu
        wxMenuItem *addAfterBt;
        wxMenuItem *addBeforeBt;

		enum State
		{
		    NOTHING, ///< Nothing to be done on the preview panel
		    DRAGGING, ///< A point is drag-dropping
		    ADDING, ///< A point will be added
		    REMOVING, ///< A point will be deleted
		    VIEWMOVING, ///< Use move the viewport of the preview panel
		    ADDINGPOINTBEFORE,
		    ADDINGPOINTAFTER
		};

		struct
		{
		    sf::Vector2f offset;
		    State state;
		    int selectedPoint;
		    sf::Vector2f originalPoint;

		    sf::Vector2f mousePosition;

		    wxBitmap *backgroundBitmap;
		} previewPnlState; ///< Contain several information about the preview panel (offset, last clicked point, state)

		bool haveDeletedAGlobalPath; ///< Used to warn the user that other objects could have been using the global path(s) removed.

		DECLARE_EVENT_TABLE()
};

template <typename CONTAINER>
void replace_key(CONTAINER& container,
                const typename CONTAINER::key_type& oldKey,
                const typename CONTAINER::key_type& newKey)
{
    if(!container.key_comp()(oldKey,newKey) && !container.key_comp()(newKey,oldKey)){
    return;} //Thanks to Graham for this Fix
    typename CONTAINER::iterator begin(container.find(oldKey));
    for(;;){
        if(begin != container.end()){
            container.insert(typename CONTAINER::value_type(newKey, begin->second));
            container.erase(begin); // Thanks to Graham for this potential fix
            begin = container.find(oldKey);
        }
        else{
            return;
        }
    }
}

#endif
#endif
