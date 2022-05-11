

customElements.define("svg-progress-circle", class extends HTMLElement {
    connectedCallback() {
        let d = 'M5,30a25,25,0,1,1,50,0a25,25,0,1,1,-50,0'; // circle
        this.innerHTML =
            `<input type="range" min="0" max="100" step="10" value="30"` + // delete 2 lines
            ` oninput="this.parentNode.percent=this.value" /><br>` + // just for demo

            `<svg viewBox="0 0 60 60">
       <path stroke-dasharray="10 2"   stroke-dashoffset="-19" 
             pathlength="120" d="${d}" fill="grey" stroke="lightgrey" stroke-width="5"/>
       <path stroke-dasharray="30 70" stroke-dashoffset="-25" 
             pathlength="100" d="${d}" fill="none" 
             stroke="${this.getAttribute("color") || "red"}" stroke-width="5"/>
       <text x="50%" y="57%" text-anchor="middle">30%</text></svg>`;

        this.style.display = 'inline-block';
        this.percent = this.getAttribute("percent");
    }
    set percent(val = 0) {
        this.setAttribute("percent", val);
        let dash = val + " " + (100 - val);
        this.querySelector("path+path").setAttribute('stroke-dasharray', dash);
        this.querySelector("text").innerHTML = val + "%";
        this.querySelector("input").value = val;
    }
})