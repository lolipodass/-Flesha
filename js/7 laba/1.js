"use strict"

function task1() {
    let form = document.forms[0];

let div=document.createElement("div");

    let p=document.createElement("p");
    p.innerHTML=`student <strong>${form.surname.value}</strong>,special<strong> ${form.spec.value}</strong>,curs <strong>${form.curs.value}</strong>, need to pass:`;
    div.append(p);

    let list=document.createElement("ul");

    let les = form.querySelectorAll('input[type="checkbox"]');
    for (let i = 0; i < les.length; i++) {
        if (les[i].checked) {
            let li=document.createElement("li");
            li.innerHTML=les[i].name
            list.appendChild(li);
        }
    }
    div.appendChild(list);
    console.log(div);
    document.body.append(div);
}

document.querySelector("input[type='reset']").addEventListener("click", task1);
document.querySelector("input[type='reset']").addEventListener("click", reset);

document.querySelector('input[type = "submit"]').onclick = (event) => {
    event.preventDefault();
    task1();
}

function task2() {
    let les = document.forms[0].querySelectorAll('input[type="checkbox"]');
    let da = document.querySelector(".sec");

    for (let i = 0; i < les.length; i++) {
        if (les[i].checked) {
            da.innerHTML += `<option value ="${les[i].name}">${les[i].name}</option>`;
        }
    }
}

function reset() {
    let da = document.querySelector(".sec");
    da.innerHTML = 0;
}