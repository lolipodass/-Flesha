"use strict"

let da=$("p");
let text = document.querySelector("p").innerHTML.split(' ');
for (let i in text) {
text[i] = `<span>${text[i]}</span>`;
}
document.querySelector("p").innerHTML = text.join(' ');

let net =$("span").mouseenter((Event)=>Event.target.style.color="orange")
net.mouseleave((Event)=>Event.target.style.color="black")
net.click((Event)=>Event.target.style.fontSize="20px")


let image=true;
let caps=true;
let img=$("img");

img.mouseenter( (Event)=>Event.target.style.width="600px");
img.mouseleave( (Event)=>Event.target.style.width="400px");
img.click( (Event)=>{
    image? Event.target.src = "../../html/images/2.jpg":Event.target.src = "../../html/images/1.jpg";
    image=!image;
});

let figcap=$("figcaption");
figcap.click(()=>{caps? figcap.html('ad'):figcap.html('da'); 
    caps=!caps;
})

let border=true;


da.dblclick((Event)=>{
    border?Event.currentTarget.style.border="5px double blue":Event.currentTarget.style.border="none";
    border=!border;
})
