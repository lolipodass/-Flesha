
import React from 'react';
import './App.css';
import JobMenu from './JobMenu';
import Clock from './Clock';

function App()
{
  return (
    <div className='main'>
      <Clock format="24" timezone="+02:00" />
      <JobMenu/>
    </div>
  )
}

export default App;
