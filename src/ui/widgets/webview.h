#ifndef WEBVIEW_H
#define WEBVIEW_H

#ifdef USE_WEBENGINE
    #include <QWebEngineView>
    #include <QWebEnginePage>
    #define QWebView QWebEngineView
    #define QWebPage QWebEnginePage
#else
    #include <QWebView>
    #include <QKeyEvent>
#endif

class WebView : public QWebView
{
    Q_OBJECT
public:
    explicit WebView(QWidget *parent = nullptr);

    int zealZoomFactor() const;
    void setZealZoomFactor(int zf);
    void setNegativeFilter(bool value) {
        m_negativeFilter = value;
        update();
    }

protected:
    QWebView *createWindow(QWebPage::WebWindowType type) override;
    void wheelEvent(QWheelEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void updateZoomFactor();

    int m_zoomFactor = 0;
    bool m_negativeFilter = false;
};

#endif // WEBVIEW_H
