#include "mainwindow.h"
#include <QApplication>
#include <QProgressDialog>
#include <QSettings>
#include <QFileInfo>
#include <QCryptographicHash>
#include <QUrl>
#include <QTextCodec>
#include <QDateTime>
#include <QDebug>

#include "stdio.h"

// custom includes
#include "zstring.h"
#include "dbg_byzed.h"
#include "ticker.h"
#include "zdmhttptest.h"
#include "zdmhttp.h"
#include "qtutil.h"
#include "singleton.h"

static QString calcMd5(const QByteArray& in, int times) {
    int r = times;
    QByteArray d = in;
    while(r-- > 0) {
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(d);
        d = hash.result().toHex().toUpper();
    }
    return QString(d);
}

static QString fromGBK(const QByteArray& data) {
    QTextCodec *c = QTextCodec::codecForName("GB2312");
    if(c == NULL) {
        return QString();
    }
    return c->toUnicode(data);
}

void fuc1(int i) {
    qDebug() << i;
}

void fuc1(unsigned int i) {
    qDebug() << i;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    fuc1(100);

//    LazySingleton *laz = LazySingleton::getInstancePtr();

//    LazySingleton::getInstance();

//    QString key = calcMd5(QString("%1%2%3").arg("luwei1").arg("315098").arg(10).toUtf8(), 1);
//    qDebug() << key << endl;


//    QUrl url("http://sjapk.dengxian.net/install.aspx?agg_id=&id=2588,2564,2603,2440,2442,2563,2334,2571,2567,2536,2420,2262,2604,2471,2315,2602,2537,2531,2518,2360,2598,2286,2589,2314,2594,2525,2579&imei=861054033253431&pwd=834278DE521BAA25062194902110A99F&userid=wh6688&ver=v3.2.9&key=E30B82803EA684AC64DEF0B83E1DCFD9&brand=letv&model=letv%20x501&version_release=5.0.2&version_sdk=21&rooted=0&agged=0&mac=74-D4-35-43-C9-C3&hwid=&sys=linux&cmd=1");

//    url.removeQueryItem("imei");
//    url.addQueryItem("imei", QString(line));

//    QString enc_imei;
//    QString enc_aggids;
//    QString enc_ids;
//    ZDMHttp::url_escape(url.queryItemValue("imei").toUtf8(), enc_imei);
//    ZDMHttp::url_escape(url.queryItemValue("agg_id").toUtf8(), enc_aggids);
//    ZDMHttp::url_escape(url.queryItemValue("id").toUtf8(), enc_ids);

//    QString query = QString("agg_id=%1&id=%2&imei=%3&pwd=%4&userid=%5&ver=%6")
//            .arg(enc_aggids, enc_ids, enc_imei, url.queryItemValue("pwd"), url.queryItemValue("userid"), url.queryItemValue("ver"));
//    QString key = calcMd5(query.toUtf8(), 5);

//    qDebug() << key;

//    url.removeQueryItem("key");
//    url.addQueryItem("key", key);


//    QtUtil::iterateDir("D:\\01Svn\\FastmanCombo2\\Packer\\packer\\Dual");

//    qDebug() << QDateTime::currentDateTime();

//    QUrl url("http://sjapk.dengxian.net/install.aspx?agg_id=&id=2559&imei=862372021542980&pwd=6CF7520327ED5768E0FA4C33D5FDC159&userid=zmmzcs&ver=v3.3.0&brand=huawei&model=huawei%20g716-l070&version_release=4.2.2&version_sdk=17&rooted=0&agged=0&mac=F0-B4-29-38-90-CB,F0-B4-29-38-90-CA,44-8A-5B-B9-BE-2B&hwid=49A2DF56-A741-4482-9A9E-E2D88AAD5942&ywun=&key=D304C218D16DB16F3501E250DB2FFA11&cmd=1");

//    QString agg_id = url.queryItemValue("agg_id");
//    QString id = url.queryItemValue("id");
//    QString imei = url.queryItemValue("imei");
//    QString pwd = url.queryItemValue("pwd");
//    QString userid = url.queryItemValue("userid");
//    QString ver = url.queryItemValue("ver");
//    QString query = QString("agg_id=%1&id=%2&imei=%3&pwd=%4&userid=%5&ver=%6")
//            .arg(agg_id, id, imei, pwd, userid, ver);
//    QString key = calcMd5(query.toUtf8(), 5);

//    qDebug() << agg_id << endl << id  << endl<< imei  << endl<< pwd  << endl<< ver << endl << key;
//    url.removeQueryItem("key");
//    url.addQueryItem("key", key);

//    QByteArray out;
//    if (0 != ZDMHttp::get(url.toString().toUtf8().data(), out)) {
//        qDebug() << "network error";
//    }


//    QFile file("text.txt");
//    if (file.open(QIODevice::ReadOnly)) {
//        while (!file.atEnd()) {
//            QByteArray line = file.readLine().trimmed();

//            qDebug() << line;

//            //
//            QUrl url("http://61.160.234.132:90/install.aspx?agg_id=&id=2588,2564,2497,2440,2442,2563,2334,2571,2406,2536,2420,2526,2262,2417,2313,2315,2471,2405,2537,2518,2360,2299,2531,2286,2443,2314&imei=860077038417207,860077038827702&pwd=3F6F2F109D6FFAD15B57C0BEE6ABA7EC&userid=015hz505mz&ver=v3.2.8&brand=huawei&model=huawei rio-al00&version_release=5.1&version_sdk=22&rooted=0&agged=0&mac=94-DE-80-5A-A0-FC&hwid=&ywun=94-DE-80-5A-A0-FC&key=417A16C0E101BBCCCB17B9FA1682433F&cmd=1");

//            url.removeQueryItem("imei");
//            url.addQueryItem("imei", QString(line));

//            QString enc_imei;
//            QString enc_aggids;
//            QString enc_ids;
//            ZDMHttp::url_escape(url.queryItemValue("imei").toUtf8(), enc_imei);
//            ZDMHttp::url_escape(url.queryItemValue("agg_id").toUtf8(), enc_aggids);
//            ZDMHttp::url_escape(url.queryItemValue("id").toUtf8(), enc_ids);

//            QString query = QString("agg_id=%1&id=%2&imei=%3&pwd=%4&userid=%5&ver=%6")
//                    .arg(enc_aggids, enc_ids, enc_imei, url.queryItemValue("pwd"), url.queryItemValue("userid"), url.queryItemValue("ver"));
//            QString key = calcMd5(query.toUtf8(), 5);

//            url.removeQueryItem("key");
//            url.addQueryItem("key", key);

//            QByteArray out;
//            char *uri = strdup(url.toEncoded().data());
//            if (0 != ZDMHttp::get(uri, out)) {
//                free(uri);
//                qDebug() << "network error";
//            }
//            qDebug() << uri;
//            free(uri);

//            qDebug() << fromGBK(out);
//        }
//    }

    return a.exec();
}
