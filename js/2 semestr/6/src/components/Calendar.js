import React from 'react'
import CalendarBody from './calendarbody'
import CalendarHead from './calendarhead'
import Notes from './Notes'
import "./../milligram.css"
import "./styleshit.css"

class Calendar extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            _date: new Date,
            _current: [],
            _vision: "invisible",
            _note_date: "",
        };
        this.monthLess = this.monthLess.bind(this);
        this.monthMore = this.monthMore.bind(this);
        this.click = this.click.bind(this);

    }

    click(event) {
        if (this.state._current.indexOf(event.target.abbr) == -1 && this.state._vision == "invisible")
            this.setState({ _current: this.state._current.concat(event.target.abbr) });
        else if (this.state._current.indexOf(event.target.abbr) > -1 && this.state._vision == "invisible") {
            this.setState({ _vision: "visible", _note_date: event.target.abbr });
            console.log(this.state._note_date)
        }
        else if (this.state._vision == "visible" && this.state._current.indexOf(event.target.abbr) > -1)
            this.setState({ _vision: "invisible", _current: this.state._current.splice(1, this.state._current.indexOf(event.target.abbr)) });
    }

    monthMore() {
        let MM = this.state._date.getMonth();
        let YYYY = this.state._date.getFullYear();
        let DD = this.state._date.getDate();
        if (MM > 10) {
            MM = -1;
            YYYY++;
            DD = this.state._date.getDate();
        }
        MM++;
        this.setState({
            _date: new Date(YYYY, MM, DD)
        });
    }

    monthLess() {

        let DD = this.state._date.getDate();
        let MM = this.state._date.getMonth();
        let YYYY = this.state._date.getFullYear();
        if (MM < 1) {
            MM = 12;
            YYYY--;

        }
        MM--;

        this.setState({
            _date: new Date(YYYY, MM, DD)
        })

    }

    render() {
        return (
            <div>
                <CalendarHead monthLess={this.monthLess} monthMore={this.monthMore} _date={this.state._date} />
                <CalendarBody _current={this.state._current} _date={this.state._date} click={this.click} />
                <br />
                <Notes note_date={this.state._note_date} vision={this.state._vision} />
            </div>
        );
    }

}
export default Calendar