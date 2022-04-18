import './flags.css'
import './App.css';
import Table from './Table';
import React, { useRef } from 'react'

function App() {
  const refUl = useRef(null);
  const refInput = useRef(null);
  let place = null;

  const data = {
    by: "+375 (__) ___-__-__",
    ru: "+7 (___) ___-__-__",
    ua: "+380 (__) ___-__-__",
    pl: "+48 ___-___-___",
    lt: "+370 (__) ___-__-__",
    lv: "+371 ____-____"
  };


  return (
    <div>
      <div className="">
        <button onClick={show}><div className="flag flag-by"></div></button>
        <input type="text" placeholder="Выберите страну" ref={refInput} onInput={mask} onFocus={mask} onClick={mask} />
      </div>

      <ul className='hidden numbers' ref={refUl} onClick={phone}>
        <li data-value="ru">ру</li>
        <li data-value="by">бел</li>
        <li data-value="ua">укр</li>
        <li data-value="pl" >польша</li>
        <li data-value="lt" >литва</li>
        <li data-value="lv">латвия</li>
      </ul>
      <Table />
    </div >
  )
  function show() {
    refUl.current.className.search("numbers") ? refUl.current.className = "numbers" : refUl.current.className = "hidden numbers";
  };

  function phone(event) {
    if (event.target == event.currentTarget) return;

    document.querySelector(".flag").className = `flag flag-${event.target.dataset.value}`;

    place = data[event.target.dataset.value];
    refInput.current.placeholder = data[event.target.dataset.value];
    refInput.current.value = place;
    mask();
  }

  function mask() {
    const { current: input } = refInput;

    let pos = input.placeholder.search("_");

    const char = +input.value.charAt(pos)

    if (Number.isInteger(char)) {

      place = place.replace("_", char);
    }
    pos = input.value.search('_');


    console.log(pos, "pos");
    console.log(place, "place");
    console.log(input.value.charAt(pos));
    // console.log(char);


    input.value = place;

    input.selectionStart = input.selectionEnd = pos;

    // if (!(target.value[0] == "+" && target.value > 0 && target.value < 9)) target.value = "jopa";

  }
}

export default App;
