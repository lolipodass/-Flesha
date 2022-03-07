
import React from 'react';
import './App.css';

class App extends React.Component
{
  render()
  {
    let options = {hour12: false};
    (this.props.format == 12) ? options.hour12=true : options.hour12=false;
    
    let data=new Date();
    console.log(Date.now()+3*600);
    console.log(options);
    return <div className='main'>{data.toLocaleString("ru-RU",options)}</div>
  }

//   constructor(props)
//   {
//     super(props);
//   }
}

export default App;
