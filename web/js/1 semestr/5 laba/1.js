"use strict"

function task1() {
    let al = document.all;
    console.log(al);
    for (let i = 0; i < al.length; i++) {
        console.log(`${al[i].tagName} №${i}  
            ${al[i].nodeType} `);
    }
}

function task2() {
    for (let i = 0; i < document.body.childNodes.length; i++) {
        console.log(document.body.childNodes[i].tagName);
    }
}

function task3() {
    let span = document.querySelector('span');
    console.log(span.innerHTML);
    let span1 = document.getElementsByTagName("span");
    console.log(span1[0].innerHTML);
    let span2 = document.getElementById("span");
    console.log(span2.innerHTML);
}

function task4() {
    let mark = document.querySelectorAll('.mark');
    let sum = 0;
    for (let i = 0; i < mark.length; i++) {
        sum += Number(mark[i].innerHTML);
    }
    sum /= mark.length;
    let sp = document.querySelectorAll("span");

    sp[1].innerHTML = sum;
    console.log(mark.length);
    return sum;


}