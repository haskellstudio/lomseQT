#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QtWidgets>

#include <iostream>

//lomse headers
#include <lomse_doorway.h>
#include <lomse_document.h>
#include <lomse_graphic_view.h>
#include <lomse_interactor.h>
#include <lomse_presenter.h>
#include <lomse_events.h>

using namespace lomse;


//forward declarations
class MyCanvas;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void open_test_document();
private slots:
    void on_about();
   protected:
       void create_actions();
       void create_menu();

       //lomse related
       void initialize_lomse();

   protected:

       //Qt stuff, for the GUI

       MyCanvas* m_canvas;
       QScrollArea* scrollArea;

       QAction* m_aboutAction;
       QAction* m_exitAction;

       QMenu* m_fileMenu;
       QMenu* m_helpMenu;

       //Lomse stuff

       LomseDoorway    m_lomse;        //the Lomse library doorway

private:
    Ui::MainWindow *ui;
};


class MyCanvas : public QWidget
{
public:
    MyCanvas(QWidget* parent, LomseDoorway& lomse);
    ~MyCanvas();

    void update_view_content();

    //commands
    void open_test_document();

protected:
    //event handlers
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent* event);

    void delete_rendering_buffer();
    void create_rendering_buffer(int width, int height);
    void update_rendering_buffer_if_needed();


        //Lomse stuff

    // In this first example we are just going to display an score on a window.
    // Let's define the necessary variables:
    LomseDoorway&   m_lomse;        //the Lomse library doorway
    Presenter*      m_pPresenter;

    //the Lomse View renders its content on a bitmap. To manage it, Lomse
    //associates the bitmap to a RenderingBuffer object.
    //It is your responsibility to render the bitmap on a window.
    //Here you define the rendering buffer and its associated memory
    //for this View
    RenderingBuffer     m_rbuf_window;
    unsigned char*      m_pdata;                    //ptr to the bitmap
    int                 m_nBufWidth, m_nBufHeight;	//size of the bitmap

    //some additinal variables
    bool    m_view_needs_redraw;      //to control when the View must be re-drawn
};


#endif // MAINWINDOW_H
