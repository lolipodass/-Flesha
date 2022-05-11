import React from 'react'

const Months = [{ tag: "January", count: 31}, { tag: "February", count: 28}, { tag: "March", count: 31}, { tag: "April", count: 30}, { tag: "May", count: 31},
    { tag: "June", count: 30 }, { tag: "July", count: 31 }, { tag: "August", count: 31 }, { tag: "September", count: 31 }, { tag: "October", count: 31 },
    { tag: "November", count: 31 }, { tag: "December", count: 31 }]

class CalendarHead extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            _date: props._date.getMonth(),
        };
       }

   
    
    render() {
        let __date
        Months.forEach((a, i, month) => {
            if (i == this.props._date.getMonth()) { __date = month[i].tag }
        })
        return (
            <div>
                <div>{__date} </div>
                <button onClick={() => { this.props.monthLess() }} > left </button> <button onClick={() => this.props.monthMore()}> right </button>
            </div>
        )
    };
}
        export default CalendarHead