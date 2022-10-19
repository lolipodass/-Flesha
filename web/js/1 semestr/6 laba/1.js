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


function openWindow() {
    let new_window = open('about:blank',)

    new_window.document.write("<h1>Hello, World!</h1>")
    new_window.document.write('<button  onclick="displayInfo()" style="margin-right: 10px;">dispay somesing</button>')
    new_window.document.write('<button value="${name} (close)" onclick="window.close()">close</button>')

    let func_script = new_window.document.createElement('script')
    func_script.innerText = `function displayInfo() { document.write('<p> - amongus!</p>')}`
    new_window.document.body.append(func_script)
}