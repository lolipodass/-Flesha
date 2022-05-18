const main = document.querySelector("main");
let num = localStorage.getItem("showItem") - 1;
const games = data.games;
draw(games[num]);


function changeElement(direction) {
    num += direction ? 1 : -1;
    num >= games.length ? num = 0 : 0;
    num < 0 ? num = games.length - 1 : 0;
    localStorage.setItem("showItem", num + 1);
    draw(games[num]);
}



function draw(dateElement) {
    main.innerHTML = `
    <div class='wrapper info' style="background:radial-gradient(circle at center -10px, rgba(0,0,0,0.5) 0%, rgba(0,0,0,1)) , url(sources/images/${dateElement.imageBig}) no-repeat center/100%">
            <button onclick="changeElement(false)" class="button left"></button>    
    <img src="sources/images/${dateElement.image}" alt="${dateElement.name}">
        <div>
        <h1 >${dateElement.name}</h1>
        ${dateElement.fullDescription}</div>
        <button onclick="changeElement(true)" class="button right"></button>
    </div>`
}

