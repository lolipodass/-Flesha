import { useId } from "react";
import "./style.css"
const amountOfDays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
var saved=0


function CalendarBody(props) {
    // console.log(saved)

    const format= Intl.DateTimeFormat("ru",{month:'2-digit'});

    
    let date=new Date(props.date);
    let row = [];
    let number=amountOfDays[date.getMonth()-1<0?11:date.getMonth()-1]-date.getDay()+1;
    let prevMonth=true;
    let index=date.getMonth()-prevMonth;
    if(index==-1)index=11;
    let classes="dark"

    for (let i = 0; i < 7*6; i++) {
        row.push(<td key={i} className={classes} onClick={saveDate} id={format.format(date)+i}>{number}</td>);
        number++;
        if(number>amountOfDays[index]){
            number=1;
            classes=classes?'':'dark';
            prevMonth=!prevMonth};
    }


    let table = [];
    let pos = 0;
    for (let i = 0; i < 7; i++) {
        table.push(<tr key={i}>
            {row.slice(pos, pos + 7)}
        </tr>)
        pos += 7;
    }

    return (table)

    function saveDate(e)
    {
        if(saved!=e.target.dataset.date&&saved!=0) return;
        e.target.className="chooses";
        saved=e.target.id;

        console.log( e.target);
        console.log(saved);
    }
    function cheek(element)
    {
        if(saved!=element.dataset.date)
        {
            element.className="";
        }
    }
}

export default CalendarBody;