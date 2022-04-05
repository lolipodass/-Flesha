

const amountOfDays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

function CalendarBody() {

    let date = new Date(2022, 0, 1);
    console.log(date);
    console.log(date.getUTCMonth());

    let row = [];
    for (let i = date.getDay(); i < amountOfDays[date.getUTCMonth()]; i++) {

        row.push(<td>{i}</td>);
    }


    let table = [];
    let pos = 0;
    for (let i = 0; i < 7; i++) {
        table.push(<tr>
            {row.slice(pos, pos + 7)}
        </tr>)
        pos += 7;
    }

    return (
        <tbody>
            {table}
        </tbody>
    )
}

export default CalendarBody;