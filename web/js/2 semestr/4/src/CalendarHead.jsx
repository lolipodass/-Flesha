import { useState } from "react"

import CalendarBody from "./CalendarBody";

function CalendarHead()
{
    let date=new Date();
    date.setDate(1);
    let[nowDate,changeDate]=useState(date);
    const format= Intl.DateTimeFormat("ru",{month:"long",year:"numeric"});

    return(
        <tbody>
            <tr>
                <th onClick={decreaseMonth}>Месяц назад</th>
                <th onClick={increaseMonth}>Месяц вперед</th>
                <th></th>
                <th>{format.format(nowDate)}</th>
            </tr>
        <tr>
            <th>Воскресенье</th>
            <th>Понедельник</th>
            <th>Вторник</th>
            <th>Среда</th>
            <th>Четверг</th>
            <th>Пятница</th>
            <th>Суббота</th>
        </tr>
        <CalendarBody date={nowDate}/>
    </tbody>
    )

    function increaseMonth(){
        changeDate((prev)=> new Date(prev.setMonth(prev.getMonth()+1)));
        // nowDate.setMonth(nowDate.getMonth()+1);
        // console.log(typeof nowDate);
    }
    function decreaseMonth(){
        changeDate((prev)=>new Date(prev.setMonth(prev.getMonth()-1)));
        // console.log(nowDate);
    }
}

export default CalendarHead;