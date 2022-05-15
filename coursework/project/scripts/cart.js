console.log(localStorage)
const games = localStorage.getItem("gameId").split(",");


const main = document.querySelector(".row");


let string = '';
for (i of games) {
    if (i == '')
        continue;

    string += `<div class="game"><img src="sources/images/${data.games[i].image}" alt="${data.games[i].name}"><span>${data.games[i].name}</span></img></div>`
}

console.log(string)
main.innerHTML = string;