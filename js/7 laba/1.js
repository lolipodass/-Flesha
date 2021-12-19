"use strict"

function task1() {
    let form = document.forms[0];

    console.log(`student ${form.surname.value},
    special ${form.spec.value},
    curs ${form.curs.value},
    need to pass 
    `)

    let les = form.querySelectorAll('input[type="checkbox"]');
    for (let i = 0; i < les.length; i++) {
        if (les[i].checked) {
            console.log(les[i].name);
        }
    }
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