#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCryptographicHash>
#include <QDebug>
#include <QImage>
#include <QColor>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QCryptographicHash md5Generator(QCryptographicHash::Sha1);
    md5Generator.addData("abcdefghijklmnopqrstuvwxyz");
    qDebug() << md5Generator.result().toHex();


    //QImage img( "file:///E:/Users/lopruben/Documents/qt/school/qml/SchoolPrinter/engine/m.bmp" );
    QImage img( ":/cmyk.bmp" );
    int cyan=0,magenta=0,yellow=0,blak=0,tmpk=0;
    if ( false == img.isNull() )
    {
        qDebug() << "Opened" << img.height() << " " << img.width();
        for ( int y = 0; y < img.height(); ++y )
        {
            for ( int x = 0; x < img.width(); ++x )
            {
                QColor clrCurrent( img.pixel( x, y ) );
                tmpk =  clrCurrent.black();
                cyan += clrCurrent.cyan() - tmpk;
                magenta += clrCurrent.magenta() - tmpk;
                yellow += clrCurrent.yellow() - tmpk;
                blak += tmpk;

            }
        }
        qDebug() << "Cyan[" << cyan/255 << "], Magenta[" << magenta/255 << "], Yellow[" << yellow/255 << "], Black["<< blak/255 <<"]";
    }
    else
    {
        qDebug() << "Error";
    }

    return app.exec();
}
