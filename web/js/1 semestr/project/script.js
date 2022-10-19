window.addEventListener('scroll', function(event) {
    let layers = document.querySelectorAll(".parallax div");
    
    let topDistance = this.scrollY;


    for (let i = 0, len = layers.length; i < len; i++) {

        let layer = layers[i];
        let depth = layer.dataset.speed;  
        let movement = -(topDistance * depth);
        layer.style.transform = `translate3d(0, ${movement}px, 0)`;
    }
  });

//   window.addEventListener('mousemove', move);
function move(event) {
    let layers = document.querySelectorAll(".parallax div");
    let middleX=this.window.innerWidth/2;
    let middleY=this.window.innerHeight/2;
    let curX=event.pageX;
    let curY=event.pageY;
    
    for (let i = 0, len = layers.length; i < len; i++) {
        let layer = layers[i];
        // layer.style.transform="scale(1.3)";
        let speed = layer.dataset.speed;  
        let x = (middleX - event.pageX)*(speed)/10;
        let y = (middleY - event.pageY)*(speed)/10;
        console.log(x);
        console.log(y);
        
        layer.style.transform = `translate(${x}px,${y}px)`
    }
};

const openPopUp = document.getElementById('open_pop_up');
const closePopUp = document.getElementById('pop_up_close');
const popUp = document.getElementById('pop_up');
let popUpBody=document.querySelector("#pop_up_body")
const garage = document.querySelectorAll(".garage");

openPopUp.addEventListener('click', function(e){
    e.preventDefault();
    popUp.classList.add('active');
    if(popUp.querySelector("img"))popUp.querySelector("img").remove();
    if(popUp.querySelector(".text"))popUp.querySelector(".text").remove();
    popUp.querySelector(".cost").innerHTML="Бесплатно";
    
})

closePopUp.addEventListener('click', () => {
    popUp.classList.remove('active');
})


$(".grid .garage").hover(function() {
    let parent=$(this);
    let child=$(this).children(".hint");
    let pos=child.position();

    child.animate({opacity: "show", top: parent.position().top-30, left: parent.position().left+32}, 200);
  }, function() {
    $(this).children(".hint").animate({opacity: "hide", top: "85"}, 400);
  });
  
let pics=document.querySelectorAll(".grid .garage");
for (let i = 0, len = pics.length; i < len; i++) {
    pics[i].addEventListener("click",info);
}

function info()
{
    if(popUp.querySelector("img"))popUp.querySelector("img").remove();
    if(popUp.querySelector(".text"))popUp.querySelector(".text").remove();

    let img=document.createElement("img");
    let cost=this.querySelector(".hint");
    let p=document.createElement("p");
    
    popUp.classList.toggle("active");

    img.src=this.querySelector("img").src;
    console.log(popUp.querySelector("p"));

    popUp.querySelector(".cost").innerHTML=cost.innerHTML;
    p.innerHTML="Хороший домик для вашей машины";
    p.setAttribute("class",'text');


    popUpBody.querySelector("p").after(img);
    img.after(p);

}