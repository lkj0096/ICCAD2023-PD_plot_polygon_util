// generated by Fast Light User Interface Designer (fluid) version 1.0400

#include "tabs.h"

Fl_Double_Window *foo_window=(Fl_Double_Window *)0;

Fl_Tabs *tabs_group=(Fl_Tabs *)0;

static void cb_Label(Fl_Group* o, void*) {
  if (Fl::callback_reason()==FL_REASON_CLOSED)
    o->parent()->remove(o);
}

static void cb_tab(Fl_Group* o, void*) {
  if (Fl::callback_reason()==FL_REASON_CLOSED)
    o->parent()->remove(o);
}

static void cb_button1(Fl_Button*, void*) {
  fl_message("Test to see if this modal window prevents you from "
             "changing the tabs. It should.");
}

static void cb_Test(Fl_Button*, void*) {
  fl_message("Make sure you cannot change the tabs while this modal window is up");
}

static void cb_tab1(Fl_Group* o, void*) {
  if (Fl::callback_reason()==FL_REASON_CLOSED)
    o->parent()->remove(o);
}

static void cb_tab4(Fl_Group* o, void*) {
  if (Fl::callback_reason()==FL_REASON_CLOSED)
    o->parent()->remove(o);
}

Fl_Wizard *wWizard=(Fl_Wizard *)0;

static void cb_button11(Fl_Button*, void*) {
  fl_message("Test to see if this modal window prevents you from "
             "changing the tabs. It should.");
}

static void cb_Test1(Fl_Button*, void*) {
  fl_message("Make sure you cannot change the tabs while this modal window is up");
}

static void cb_(Fl_Button*, void*) {
  wWizard->value(wWizard->child(0));
}

static void cb_1(Fl_Button*, void*) {
  wWizard->prev();
}

static void cb_2(Fl_Button*, void*) {
  wWizard->next();
}

static void cb_3(Fl_Button*, void*) {
  int last = wWizard->children()-1;
  wWizard->value(wWizard->child(last));
}

static void cb_add(Fl_Button*, void*) {
  static int n = 6;
  int X = tabs_group->x(), Y = tabs_group->y()+25;
  int W = tabs_group->w(), H = tabs_group->h()-25;
  Fl_Group::current(NULL);
  char buf[64];
  snprintf(buf, 62, "tab%d", n);
  Fl_Group* new_tab = new Fl_Group(X, Y, W, H);
  new_tab->copy_label(buf);
  new_tab->when(FL_WHEN_CLOSED);
  new_tab->callback((Fl_Callback*)cb_tab);
  snprintf(buf, 62, "Empty tab %d.", n);
  Fl_Box* box = new Fl_Box(X+5, Y+5, W-10, H-10);
  box->copy_label(buf);
  box->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
  tabs_group->add(new_tab);
  n++;
}

static void cb_compress(Fl_Menu_*, void*) {
  tabs_group->handle_overflow(Fl_Tabs::OVERFLOW_COMPRESS);
}

static void cb_clip(Fl_Menu_*, void*) {
  tabs_group->handle_overflow(Fl_Tabs::OVERFLOW_CLIP);
}

static void cb_pulldown(Fl_Menu_*, void*) {
  tabs_group->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
}

static void cb_drag(Fl_Menu_*, void*) {
  tabs_group->handle_overflow(Fl_Tabs::OVERFLOW_DRAG);
}

Fl_Menu_Item menu_overflow[] = {
 {"compress", 0,  (Fl_Callback*)cb_compress, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"clip", 0,  (Fl_Callback*)cb_clip, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"pulldown", 0,  (Fl_Callback*)cb_pulldown, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"drag", 0,  (Fl_Callback*)cb_drag, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

static void cb_cancel(Fl_Button*, void*) {
  exit(1);
}

static void cb_OK(Fl_Return_Button*, void*) {
  exit(0);
}

int main(int argc, char **argv) {
  { foo_window = new Fl_Double_Window(660, 400, "Comparison of Fl_Tab (left) vs. Fl_Wizard (right)");
    { Fl_Box* o = new Fl_Box(95, 0, 130, 35, "class Fl_Tabs");
      o->labeltype(FL_ENGRAVED_LABEL);
      o->labelfont(1);
    } // Fl_Box* o
    { tabs_group = new Fl_Tabs(10, 35, 315, 260);
      tabs_group->tooltip("the various index cards test different aspects of the Fl_Tabs widget");
      tabs_group->selection_color((Fl_Color)4);
      tabs_group->labelcolor(FL_BACKGROUND2_COLOR);
      { Fl_Group* o = new Fl_Group(10, 60, 315, 235, "Label&1");
        o->tooltip("this tab tests correct keyboard navigation between text input fields");
        o->selection_color((Fl_Color)1);
        o->callback((Fl_Callback*)cb_Label);
        o->when(FL_WHEN_CLOSED);
        { Fl_Input* o = new Fl_Input(70, 80, 240, 40, "input:");
          o->tooltip("This is the first input field");
        } // Fl_Input* o
        { Fl_Input* o = new Fl_Input(70, 120, 240, 30, "input2:");
          o->tooltip("");
        } // Fl_Input* o
        { new Fl_Input(70, 150, 240, 80, "input3:");
        } // Fl_Input* o
        o->end();
        Fl_Group::current()->resizable(o);
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(10, 60, 315, 235, "tab&2");
        o->tooltip("tab2 tests among other things the cooperation of modal windows and tabs");
        o->selection_color((Fl_Color)2);
        o->callback((Fl_Callback*)cb_tab);
        o->when(FL_WHEN_CLOSED);
        o->hide();
        { Fl_Button* o = new Fl_Button(20, 85, 100, 30, "button1");
          o->callback((Fl_Callback*)cb_button1);
        } // Fl_Button* o
        { new Fl_Input(130, 130, 175, 30, "input in box2");
        } // Fl_Input* o
        { new Fl_Button(25, 170, 280, 30, "This is stuff inside the Fl_Group \"tab2\"");
        } // Fl_Button* o
        { Fl_Button* o = new Fl_Button(25, 200, 280, 30, "Test event blocking by modal window");
          o->callback((Fl_Callback*)cb_Test);
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(10, 60, 315, 235, "tab&3");
        o->tooltip("tab3 checks for correct keyboard navigation");
        o->selection_color((Fl_Color)3);
        o->callback((Fl_Callback*)cb_tab1);
        o->when(FL_WHEN_CLOSED);
        o->hide();
        { new Fl_Button(20, 80, 60, 80, "button2");
        } // Fl_Button* o
        { new Fl_Button(80, 80, 60, 80, "button");
        } // Fl_Button* o
        { new Fl_Button(140, 80, 60, 80, "button");
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(10, 60, 315, 235, "&tab4");
        o->tooltip("this tab shows the issue of indicating a selected tab if the tab layouts are \
very similar");
        o->selection_color((Fl_Color)5);
        o->labeltype(FL_ENGRAVED_LABEL);
        o->labelfont(2);
        o->callback((Fl_Callback*)cb_tab4);
        o->when(FL_WHEN_CLOSED);
        o->hide();
        { new Fl_Button(20, 80, 60, 120, "button2");
        } // Fl_Button* o
        { new Fl_Button(80, 80, 60, 120, "button");
        } // Fl_Button* o
        { new Fl_Button(140, 80, 60, 120, "button");
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(10, 60, 315, 235, "@fileprint  &print");
        o->tooltip("tab5 verifies if visibility requests are handled correctly");
        o->hide();
        { Fl_Button* o = new Fl_Button(20, 80, 60, 80, "button2");
          o->tooltip("button2 has a different tooltip than tab5");
        } // Fl_Button* o
        { new Fl_Button(90, 80, 60, 80, "button");
        } // Fl_Button* o
        { Fl_Clock* o = new Fl_Clock(185, 80, 120, 120, "Make sure this clock does not use processor time when this tab is hidden or w\
indow is iconized");
          o->box(FL_OSHADOW_BOX);
          o->color((Fl_Color)238);
          o->selection_color(FL_FOREGROUND_COLOR);
          o->labelfont(8);
          o->labelsize(10);
          o->align(Fl_Align(130));
        } // Fl_Clock* o
        { Fl_Window* o = new Fl_Window(20, 190, 40, 55);
          o->box(FL_THIN_DOWN_BOX);
          o->color((Fl_Color)173);
          o->selection_color(FL_BACKGROUND_COLOR);
          o->labeltype(FL_NORMAL_LABEL);
          o->labelfont(0);
          o->labelsize(14);
          o->labelcolor(FL_FOREGROUND_COLOR);
          o->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
          o->when(FL_WHEN_RELEASE);
          o->end();
        } // Fl_Window* o
        { Fl_Window* o = new Fl_Window(65, 190, 40, 55, "subwindows:");
          o->box(FL_THIN_DOWN_BOX);
          o->color((Fl_Color)167);
          o->selection_color(FL_BACKGROUND_COLOR);
          o->labeltype(FL_NORMAL_LABEL);
          o->labelfont(0);
          o->labelsize(14);
          o->labelcolor(FL_FOREGROUND_COLOR);
          o->align(Fl_Align(FL_ALIGN_TOP));
          o->when(FL_WHEN_RELEASE);
          o->end();
        } // Fl_Window* o
        { Fl_Window* o = new Fl_Window(110, 190, 40, 55);
          o->box(FL_THIN_DOWN_BOX);
          o->color((Fl_Color)239);
          o->selection_color(FL_BACKGROUND_COLOR);
          o->labeltype(FL_NORMAL_LABEL);
          o->labelfont(0);
          o->labelsize(14);
          o->labelcolor(FL_FOREGROUND_COLOR);
          o->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
          o->when(FL_WHEN_RELEASE);
          o->end();
        } // Fl_Window* o
        o->end();
      } // Fl_Group* o
      // tabs_group->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
      tabs_group->end();
      Fl_Group::current()->resizable(tabs_group);
    } // Fl_Tabs* tabs_group
    { Fl_Box* o = new Fl_Box(410, 0, 130, 35, "class Fl_Wizard");
      o->labeltype(FL_ENGRAVED_LABEL);
      o->labelfont(1);
    } // Fl_Box* o
    { wWizard = new Fl_Wizard(330, 35, 320, 260);
      { Fl_Group* o = new Fl_Group(330, 60, 320, 235, "Label1");
        o->tooltip("this tab tests correct keyboard navigation between text input fields");
        o->selection_color((Fl_Color)1);
        o->hide();
        { Fl_Input* o = new Fl_Input(390, 80, 240, 40, "input:");
          o->tooltip("This is the first input field");
        } // Fl_Input* o
        { Fl_Input* o = new Fl_Input(390, 120, 240, 30, "input2:");
          o->tooltip("");
        } // Fl_Input* o
        { new Fl_Input(390, 150, 240, 80, "input3:");
        } // Fl_Input* o
        o->end();
        Fl_Group::current()->resizable(o);
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(330, 60, 320, 235, "tab2");
        o->tooltip("tab2 tests among other things the cooperation of modal windows and tabs");
        o->selection_color((Fl_Color)2);
        o->hide();
        { Fl_Button* o = new Fl_Button(350, 85, 100, 30, "button1");
          o->callback((Fl_Callback*)cb_button11);
        } // Fl_Button* o
        { new Fl_Input(455, 130, 175, 30, "input in box2");
        } // Fl_Input* o
        { new Fl_Button(350, 170, 280, 30, "This is stuff inside the Fl_Group \"tab2\"");
        } // Fl_Button* o
        { Fl_Button* o = new Fl_Button(350, 200, 280, 30, "Test event blocking by modal window");
          o->callback((Fl_Callback*)cb_Test1);
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(330, 60, 320, 235, "tab3");
        o->tooltip("tab3 checks for correct keyboard navigation");
        o->selection_color((Fl_Color)3);
        o->hide();
        { new Fl_Button(350, 80, 60, 80, "button2");
        } // Fl_Button* o
        { new Fl_Button(410, 80, 60, 80, "button");
        } // Fl_Button* o
        { new Fl_Button(470, 80, 60, 80, "button");
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(330, 60, 320, 235, "tab4");
        o->tooltip("this tab shows the issue of indicating a selected tab if the tab layouts are \
very similar");
        o->selection_color((Fl_Color)5);
        o->labelfont(2);
        o->hide();
        { new Fl_Button(350, 80, 60, 120, "button2");
        } // Fl_Button* o
        { new Fl_Button(410, 80, 60, 120, "button");
        } // Fl_Button* o
        { new Fl_Button(470, 80, 60, 120, "button");
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(330, 60, 320, 235, "     tab5      ");
        o->tooltip("tab5 verifies if visibility requests are handled correctly");
        o->labeltype(FL_ENGRAVED_LABEL);
        { Fl_Button* o = new Fl_Button(350, 80, 60, 80, "button2");
          o->tooltip("button2 has a different tooltip than tab5");
        } // Fl_Button* o
        { new Fl_Button(420, 80, 60, 80, "button");
        } // Fl_Button* o
        { Fl_Clock* o = new Fl_Clock(510, 80, 120, 120, "Make sure this clock does not use processor time when this tab is hidden or w\
indow is iconized");
          o->box(FL_OSHADOW_BOX);
          o->color((Fl_Color)238);
          o->selection_color(FL_FOREGROUND_COLOR);
          o->labelfont(8);
          o->labelsize(10);
          o->align(Fl_Align(130));
        } // Fl_Clock* o
        { Fl_Window* o = new Fl_Window(350, 190, 40, 55);
          o->box(FL_THIN_DOWN_BOX);
          o->color((Fl_Color)173);
          o->selection_color(FL_BACKGROUND_COLOR);
          o->labeltype(FL_NORMAL_LABEL);
          o->labelfont(0);
          o->labelsize(14);
          o->labelcolor(FL_FOREGROUND_COLOR);
          o->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
          o->when(FL_WHEN_RELEASE);
          o->end();
        } // Fl_Window* o
        { Fl_Window* o = new Fl_Window(395, 190, 40, 55, "subwindows:");
          o->box(FL_THIN_DOWN_BOX);
          o->color((Fl_Color)167);
          o->selection_color(FL_BACKGROUND_COLOR);
          o->labeltype(FL_NORMAL_LABEL);
          o->labelfont(0);
          o->labelsize(14);
          o->labelcolor(FL_FOREGROUND_COLOR);
          o->align(Fl_Align(FL_ALIGN_TOP));
          o->when(FL_WHEN_RELEASE);
          o->end();
        } // Fl_Window* o
        { Fl_Window* o = new Fl_Window(440, 190, 40, 55);
          o->box(FL_THIN_DOWN_BOX);
          o->color((Fl_Color)239);
          o->selection_color(FL_BACKGROUND_COLOR);
          o->labeltype(FL_NORMAL_LABEL);
          o->labelfont(0);
          o->labelsize(14);
          o->labelcolor(FL_FOREGROUND_COLOR);
          o->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
          o->when(FL_WHEN_RELEASE);
          o->end();
        } // Fl_Window* o
        o->end();
      } // Fl_Group* o
      wWizard->end();
    } // Fl_Wizard* wWizard
    { Fl_Group* o = new Fl_Group(410, 305, 130, 25);
      { Fl_Button* o = new Fl_Button(410, 305, 30, 25, "@|<");
        o->tooltip("go to first page [Home]");
        o->shortcut(0xff50);
        o->callback((Fl_Callback*)cb_);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(440, 305, 30, 25, "@<");
        o->tooltip("go to previous page [left arrow]");
        o->shortcut(0xff51);
        o->callback((Fl_Callback*)cb_1);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(480, 305, 30, 25, "@>");
        o->tooltip("go to next page in wizard [right arrow]");
        o->shortcut(0xff53);
        o->callback((Fl_Callback*)cb_2);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(510, 305, 30, 25, "@>|");
        o->tooltip("go to last page [End]");
        o->shortcut(0xff57);
        o->callback((Fl_Callback*)cb_3);
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    { Fl_Button* o = new Fl_Button(60, 309, 70, 25, "add tab");
      o->tooltip("Add more tabs to check overflow handling.");
      o->callback((Fl_Callback*)cb_add);
    } // Fl_Button* o
    { Fl_Choice* o = new Fl_Choice(212, 309, 95, 25, "overflow:");
      o->tooltip("Change how Fl_Tabs handles more tabs than fit into the tabs space.");
      o->down_box(FL_BORDER_BOX);
      o->menu(menu_overflow);
    } // Fl_Choice* o
    { new Fl_Input(60, 345, 250, 25, "input:");
    } // Fl_Input* o
    { Fl_Button* o = new Fl_Button(490, 345, 70, 30, "cancel");
      o->callback((Fl_Callback*)cb_cancel);
    } // Fl_Button* o
    { Fl_Return_Button* o = new Fl_Return_Button(570, 345, 70, 30, "OK");
      o->callback((Fl_Callback*)cb_OK);
    } // Fl_Return_Button* o
    foo_window->end();
  } // Fl_Double_Window* foo_window
  foo_window->show(argc, argv);
  return Fl::run();
}
