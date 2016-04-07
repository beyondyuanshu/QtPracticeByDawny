#include "zdmhttptest.h"

#include <QUrl>
#include <QVariantMap>
#include <QVariantList>

#include "zlog.h"
#include "zdmhttp.h"
#include "parser.h"

ZDMHttpTest::ZDMHttpTest(QObject *parent) : QObject(parent)
{

}

void ZDMHttpTest::getTest()
{
    // Prepare
    QUrl url("http://sjapk.dengxian.net/GetDesktop.ashx");
    QString query = QString("action=getadaptivelist");
#ifdef USE_QT5
    url.setQuery(checkInstalledQuery);
#else
    url.setEncodedQuery(query.toLocal8Bit());
#endif

    // Action
    QByteArray out;
    char *uri = strdup(url.toEncoded().data());
    if(0 != ZDMHttp::get(uri, out)) {
        DBG("connect server fail\n");
        free(uri);
    }
    DBG("<%s>\nout = <%s>\n", uri, out.data());
    free(uri);

    // Parse
    QJson::Parser p;
    QVariantMap map;
    QVariantList list;
    map = p.parse(/*ZStringUtil::fromGBK(out).toUtf8()*/out).toMap();
    list = map.find("brands").value().toList();
    foreach (const QVariant &va, list) {
        //
        DBG("Get brand:%s\n", qPrintable(va.toString()));
    }
}

void ZDMHttpTest::postTest()
{
    // Prepare
    QUrl url;
    url.setUrl("http://www.hzdengxian.com/api/linktype.aspx");
    QString params;

    // Action
    QByteArray out;
    int postRet;
    postRet = ZDMHttp::post(url.toString().toUtf8().data(), params.toUtf8().data(), out);
    DBG("Get supporter: %s\n", out.data());
    if (0 != postRet) {
        DBG("Connect server fail when post!\n");
        //
    }

    // Parse
}
