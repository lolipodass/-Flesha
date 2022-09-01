function popUp(str) {
    const popUp = document.querySelector(".pop-up");
    popUp.innerHTML = str;
    popUp.classList.add("animate");
    let func = function () { popUp.classList.remove("animate") };
    window.setTimeout(func, 2000)
}