"use strict"

document.getElementsByClassName("dragable")[0].addEventListener("mousedown",dragCheck);

function dragCheck(event)
{
    console.log(event.target.tagName);
    if(event.target.tagName=="IMG") draging(event);
    if(event.target.tagName=="TEXTAREA") 
    {
        let rect=event.target.getBoundingClientRect();

        let shiftX = event.clientX - rect.left;
        let shiftY = event.clientY - rect.top;

        if((rect.width-20)<shiftX&&(rect.height-20)<shiftY) return 0;
        draging(event);
    }
}

function draging(event) {
    let drag=event.target;
    drag.style.position = 'absolute';
    drag.style.zIndex = 1000; 
    moveAt(event);

    document.addEventListener('mousemove', moveAt);

    drag.onmouseup = function() {
      document.removeEventListener('mousemove', moveAt);
      drag.onmouseup = null;
    };

    function moveAt(event) { 
      drag.style.left = event.pageX - drag.offsetWidth / 2 + 'px';
      drag.style.top = event.pageY - drag.offsetHeight / 2 + 'px';
    }
    drag.ondragstart =()=>{return false};
};

let move=document.getElementById("move");
move.onclick = () =>{

  move.style.position="absolute";
  
  let start = Date.now();
  
  let timer = setInterval( ()=> {
    let timeLeft = Date.now() - start;
  
    move.style.left = timeLeft / 2 + 'px';
  
    if (timeLeft/2 +50> window.innerWidth) clearInterval(timer);
  });
}


let move2=document.getElementById("move2");
move2.onclick = () =>{
  move2.style.position="relative";
  let start = Date.now();
  
  let timer = setInterval( ()=> {
    let timeLeft = (Date.now() - start)/10;

    let posX=0;
    let posY=0;

    if(timeLeft<300) posY=timeLeft;
    if(timeLeft>300&&timeLeft<600) {
      posY=(600-timeLeft);
      posX=timeLeft-300;
    }
    if(timeLeft>600)
    {
      posX=900-timeLeft;
    }

    move2.style.left = posX + 'px';
    move2.style.top = posY + 'px';
    
    if (timeLeft> 900) clearInterval(timer);
  });0
}

let nav=document.querySelector("nav");
nav.querySelectorAll(".submenu").forEach((element)=>element.setAttribute("hidden",0))

let menu=nav.children;
for (let elem of menu) {
 elem.addEventListener("mouseenter",()=>elem.children[0].removeAttribute("hidden"));
 elem.addEventListener("mouseleave",()=>elem.children[0].setAttribute("hidden",0));
}