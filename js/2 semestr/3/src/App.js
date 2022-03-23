import './flags.css'
import './App.css';
import React from 'react'

class App extends React.Component {
  render() {

    return (
      <div>
        <div className="">
          <button onClick='show'><div className="flag flag-by"></div></button>
          <input type="text" placeholder="jopa" />
        </div>

        <ul className='hidden numbers' id="1">
          <li>ру</li>
          <li>бел</li>
          <li>укр</li>
          <li>польша</li>
          <li>литва</li>
          <li>латвия</li>
        </ul>
      </div>)
  }

  show() {

  }

}


export default App;
