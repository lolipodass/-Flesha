"use strict"


$(".dragable").mousedown(dragCheck);
// document.getElementsByClassName("dragable")[0].addEventListener("mousedown",dragCheck);

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

// let move=document.getElementById("move");
let move=$("#move");

move.click( ()=>{
  move.animate({left: "+=800"}, 2000);
  move.animate({left: "-=800"}, 2000);
})


let move2=$("#move2");
move2.click ( () =>{
  move2.animate({top: "+=300"}, 2000);
  move2.animate({left: "+=300",top:"-=300"}, 2000);
  move2.animate({left: "-=300"}, 2000);
})

// let nav=document.querySelector("nav");

// let nav=$("nav");

$("nav .menu-item").hover(function() {
  $(this).children(".submenu").animate({opacity: "show", top: "45"}, 200);
}, function() {
  $(this).children(".submenu").animate({opacity: "hide", top: "85"}, 400);
});



// nav.querySelectorAll(".submenu").forEach((element)=>element.setAttribute("hidden",0))

// let menu=nav.children;
// for (let elem of menu) {
//  elem.addEventListener("mouseenter",()=>elem.children[0].removeAttribute("hidden"));
//  elem.addEventListener("mouseleave",()=>elem.children[0].setAttribute("hidden",0));
// }