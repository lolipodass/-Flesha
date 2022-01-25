"use strict"

let da=document.querySelector("p");
let text = da.innerHTML.split(' ');
for (let i in text) {
text[i] = `<span>${text[i]}</span>`;
}
da.innerHTML = text.join(' ');

for(let net of document.querySelectorAll("span"))
{
    net.addEventListener("mouseenter", (Event)=>Event.target.style.color="orange");
    net.addEventListener("mouseleave", (Event)=>Event.target.style.color="black");
    net.addEventListener("click", (Event)=>Event.target.style.fontSize="20px");
}
let img=document.querySelector("img");

img.addEventListener("mouseenter", (Event)=>Event.target.style.width="600px");
img.addEventListener("mouseleave", (Event)=>Event.target.style.width="400px");

let figcap=document.querySelector("figcaption");
let caps=true;
figcap.addEventListener("click",(Event)=>
{
    if(caps) figcap.innerHTML="ad";
    if(!caps) figcap.innerHTML="da";
    caps=!caps;
})

let image=true;
let border=true;

img.addEventListener("click", (Event)=>{
    image? Event.target.src = "../../html/images/2.jpg":Event.target.src = "../../html/images/1.jpg";
    image=!image;
})

da.addEventListener("dblclick",(Event)=>{
    border?Event.currentTarget.style.border="5px double blue":Event.currentTarget.style.border="none";
    border=!border;
})
