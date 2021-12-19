task1 = {
    first() {
        location.assign("1.js");
    },
    second() {
        history.forward();
    },
}

function task2() {

    data = {
        userAgent: navigator.userAgent,
        version: navigator.appVersion,
        name: navigator.appName,
        os: navigator.platform,
        jsIsOn: navigator.javaEnabled(),
        depth: screen.colorDepth,
        history: history.length,
        url: location.href,
        source: location.pathname,
        domen: location.host,
    }
    console.table(data);
}