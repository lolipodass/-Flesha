"use strict"

document.querySelector("main").addEventListener('click', checkClick);
document.querySelector(".button-back").addEventListener('click', toggleInformation);
document.querySelector(".button-add-game").addEventListener('click', addGameToCart);


const genre = document.querySelectorAll(".genre");
for (let i = 0; i < genre.length; i++) {
    genre[i].innerHTML = data.genres[i].RusName;
    genre[i].style.backgroundColor = data.genres[i].color;
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

    const elem = data.games.find((elem) => elem.id == parent.dataset.id);
    if (elem.id == information.dataset.id && information.classList) {
        information.classList.add("hidden")
        console.log("jopa")
    }
    else
        changeInformation(elem);
}

function changeInformation(elem) {
    information.setAttribute("data-id", elem.id)
    information.children[2].src = `sources/images/${elem.image}`;
    information.children[3].innerHTML = elem.name;
    information.children[4].innerHTML = elem.description;
    information.classList.remove("hidden")
}



function toggleInformation(id) {
    information.classList.toggle("hidden");
}

function addGameToCart(e) {
    const store = (localStorage.getItem("gameId") ?? "");
    localStorage.setItem("gameId", store + ',' + e.target.parentElement.dataset.id)
    console.log(localStorage);
}