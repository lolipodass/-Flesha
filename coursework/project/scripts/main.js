"use strict"

document.querySelector("main").addEventListener('click', checkClick);
document.querySelector(".button-back").addEventListener('click', toggleInformation);
document.querySelector(".button-add-game").addEventListener('click', addGameToCart);


document.querySelector('h1.header').innerHTML = `hello ${localStorage.getItem("name") ?? "UserName"}`;

const genre = document.querySelectorAll(".genre");
for (let i = 0; i < genre.length; i++) {
    genre[i].innerHTML = data.genres[i].RusName;
    genre[i].style.backgroundColor = data.genres[i].color;
    genre[i].setAttribute("data-genre", data.genres[i].EngName);
}

const lastGames = document.querySelectorAll(".recent-game");
for (const element of lastGames) {
    const dataElement = data.games[Math.round((Math.random() * 100)) % data.games.length];
    element.firstElementChild.src = `sources/images/${dataElement.image}`;
    element.lastElementChild.innerHTML = dataElement.name;
    element.dataset.id = dataElement.id;
}

const game = document.querySelectorAll(".game");
for (let i = 0; i < game.length; i++) {
    game[i].setAttribute("data-id", data.games[i].id)
    game[i].children[0].src = `sources/images/${data.games[i].image}`;
    game[i].children[1].innerHTML = data.games[i].name;
}





function checkClick(e) {
    const parent = e.target.closest(".game,.genre,.recent-game")
    if (parent === null)
        return;

    if (parent.matches(".recent-game"))
        changeInformation(data.games[parent.dataset.id - 1]);


    if (parent.matches(".genre"))
        gameRow(e.target.dataset.genre);

    if (parent.matches(".game")) {
        const elem = data.games.find((elem) => elem.id == parent.dataset.id);
        if (elem.id == information.dataset.id && information.classList)
            toggleInformation()
        else
            changeInformation(elem);
    }

}

function gameRow(genre) {
    const game = document.querySelectorAll(".row")[2];
    game.innerHTML = "";
    console.log(game)
    const arr = data.games.filter((elem) => elem.genres.includes(genre));
    if (arr.length == 0)
        game.innerHTML = "<h2>Элементов нет</h2>"
    for (const i of arr) {
        game.innerHTML += `<div class="game" data-id="${i.id}"> <img src="sources/images/${i.image}" alt="${i.name}"></img><span>${i.name}</span></div>`
    }
}

function changeInformation(elem) {
    information.setAttribute("data-id", elem.id)
    information.children[2].src = `sources/images/${elem.image}`;
    information.children[3].innerHTML = `<a href="gameDescription.html" onclick="pageDescription()">${elem.name}</a>`;
    information.children[4].innerHTML = elem.description;
    const svg = information.children[5].querySelectorAll("svg")
    for (let i = 0; i < svg.length; i++) {
        svg[i].firstElementChild.className.baseVal = `score-value mark-${elem.rating[i]}`
        svg[i].children[1].innerHTML = elem.rating[i];
    }


    information.classList.remove("hidden")
}


function pageDescription() {
    localStorage.setItem("showItem", information.dataset.id)
}


function toggleInformation(id) {
    information.classList.toggle("hidden");
}

function addGameToCart(e) {
    popUp("элемент добавлен в корзину")
    const store = (localStorage.getItem("gameId") ?? "");
    localStorage.setItem("gameId", store + ',' + e.target.parentElement.dataset.id)
    console.log(localStorage);
}