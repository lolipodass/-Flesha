console.log(localStorage)
let string = "Корзина пуста";
const games = localStorage.getItem("gameId")?.split(",");
const main = document.querySelector(".row");

if (games != undefined) {
    const map = new Set(games);


    string = '';
    for (i of map) {
        if (i == '')
            continue;
        i -= 1;
        string += `<div class="game"><img src="sources/images/${data.games[i].image}" alt="${data.games[i].name}"><span>${data.games[i].name}</span></img></div>`
    }

}
console.log(string);

main.innerHTML = string;



function clearCart() {
    localStorage.clear();
    document.location.reload()
}
