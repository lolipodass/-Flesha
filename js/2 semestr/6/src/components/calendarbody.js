import React from 'react'
import './styleshit.css'

 

class CalendarBody extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            _date: props,
        };
        this.clr = this.clr.bind(this);
        this.dateToStr = this.dateToStr.bind(this);
    }

    clr(tdArr) {
        let className;
        if (this.props._current.indexOf(this.dateToStr(tdArr)) > -1) { className = "choice" }
        else if (this.props._date.getMonth() != tdArr.getMonth()) { className = "lessthree" }
        else if (this.state._date._date.getDate() == tdArr.getDate()) { className = "zero" }

        return className;
    }

    dateToStr(count) {
        return count.getFullYear() + (count.getMonth() > 8 ? "-" : "-0") + (1 + count.getMonth()) + (count.getDate() > 9 ? "-" : "-0") + count.getDate()

    }

    render() {
        console.log(this.props._current);
        let MM = this.props._date.getMonth();
        let YYYY = this.props._date.getFullYear();
        let DD = this.props._date.getDate();
        let thisMonth = new Date(YYYY, MM, DD);
        let const1 = thisMonth.getDay();
        let trArr = []; let Arr = [];
        for (let i = const1; i < 42; i++) trArr[i] = new Date(YYYY, MM, 1 + i - const1);
        for (let i = 0; i < const1; i++) trArr[i] = new Date(YYYY, MM, - i);
        trArr.sort((a, b) => a > b ? 1 : -1);
        for (let i = 0; i < 6; i++) {
            let tdArr = [];
            for (let j = 0; j < 7; j++) tdArr[j] = trArr[j + i * 7];

            Arr.push(tdArr);
        }

        return (
            <div style={{ textAlign: "-webkit-center"}}>
                <table>
                    <thead>
                        <tr>
                            <td> Mon </td> <td> Tue </td> <td> Wed </td> <td> Thu </td> <td> Fri </td> <td> Sat </td> <td> Sun </td>
                        </tr>
                    </thead>
                    <tbody>
                        {Arr.map((tdArr) => 
                            (
                            <tr>
                                {tdArr.map((count) => (<td abbr={this.dateToStr(count)} class={this.clr(count)} onClick={(event) => { this.props.click(event); }}> {count.getDate()}</td>))}
                                </tr>
                            )
                        )}
                    </tbody>
                </table>
            </div>
        )
    };
}
        export default CalendarBody
