//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}

#include <iostream>
#include <thread>
#include <chrono>
#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QMultiMap>
#include <QTextStream>

void foo()
{
    // 模拟昂贵操作
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "foo1" << std::endl;
}

void bar()
{
    // 模拟昂贵操作
    std::this_thread::sleep_for(std::chrono::seconds(6));
    std::cout << "bar1" << std::endl;
}

void test(int t)
{
    qDebug()<<t;
}

void la(std::function<void(int)> func)
{
    auto temp = [&](int b){
        qDebug()<<"la:  "<<b;
        func(b);
    };
    int a = 10;
    temp(a);
}

struct LineData
{
    LineData(const QString &_name,const QString &_x,const QString &_y,const QMultiMap<QString,QString> &map):name(_name),x(_x),y(_y),type(map) {}
    QString name;
    QString x;
    QString y;
    QMultiMap<QString,QString> type;
};

void propertySingle()
{
    QFile in(u8"E:\\work\\地质保障系统\\水文地质数据\\成果数据\\自已处理\\精简合并整理\\钻孔0117_无最后底板.csv");
    in.open(QIODevice::ReadOnly);
    QString head = in.readLine();
    QString n,x,y,ptid;
    QVector<LineData> datalist;
    QMultiMap<QString,QString> type;
    QVector<QString> hors;
    while (!in.atEnd()) {
        QString data = in.readLine().simplified();
        QStringList cr = data.split(",");
        if(cr.size() != 5)
            continue;
        if(type.size() > 0 && ptid != cr[0])
        {
            LineData data{cr[0],cr[1],cr[2],type};
            datalist.push_back(data);
            type.clear();
            ptid = cr[0];
        }
        type.insert(cr[4],cr[3]);
        n = cr[0];
        x = cr[1];
        y = cr[2];
        if(!hors.contains(cr[4]))
            hors.push_back(cr[4]);
    }
    LineData data{n,x,y,type};
    datalist.push_back(data);
    in.close();
    for(const auto &hor : hors)
    {
        QString filename = u8"E:\\work\\地质保障系统\\水文地质数据\\成果数据\\自已处理\\精简合并整理\\钻孔0117_无最后底板_" + hor + ".csv";
        in.setFileName(filename);
        in.open(QIODevice::WriteOnly);
        QTextStream stream(&in);
        if(datalist.size() > 0)
        {
            stream << "name,x,y,hor";
        }
        for(const auto &d : datalist)
        {
            QList<QString> tv = d.type.values(hor);
            for(const auto &t : tv)
            {
                stream << Qt::endl << d.name << "," << d.x << "," << d.y << "," << t;
            }
        }
        in.close();
    }
}


int main1()
{
    QFile out(u8"E:\\work\\project\\gms\\0129\\odata\\4开采量\\kacailiang.csv");
    out.open(QIODevice::WriteOnly);
    QTextStream stream(&out);
    stream << "name,date,time,value";
    QString time = " 0:00:00";
    QFile in(u8"E:\\work\\project\\gms\\0129\\odata\\4开采量\\开采量.csv");
    in.open(QIODevice::ReadOnly);
    QString data = in.readLine().simplified();
    QStringList heads = data.split(",");
    if(heads.size() < 3)
        return 0;
    while (!in.atEnd()) {
        data = in.readLine().simplified();
        QStringList cr = data.split(",");
        if(cr.size() != heads.size())
            continue;
        for(int i = 3; i < cr.size(); ++ i)
        {
            stream << Qt::endl << cr[0] << "," << heads[i] << "," << time << "," << cr[i];
        }
    }
    in.close();
    out.close();

    return 0;
    std::cout << "starting first helper..." << std::endl;
    std::thread helper1(foo);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "starting second helper..." << std::endl;
    std::thread helper2(bar);
    std::cout << "waiting for helpers to finish..." << std::endl;

    helper2.join();
    helper1.join();
    std::cout << "done!" << std::endl;
    getchar();
}
