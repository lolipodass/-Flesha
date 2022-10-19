export default ChessBoard;


function ChessBoard()
{
    let arr=[];
    let bool=1;
    arr.push(firstRow());
    for (let num = 1; num < 9; num++) {
        arr.push(
        <tr>
            <td className="letters">{num}</td>
            {line(bool)}
            <td className="letters">{num}</td>
        </tr>)
        bool=!bool;
        
    }
    arr.push(firstRow());
    return arr;
}

function firstRow()
{
    let letters=[' ','a','b','c','d','e','f','g','h',' '];
    let line=[];
    for (let letter = 0; letter < letters.length; letter++) {
    
        line.push(
            <td className="letters">{letters[letter]}</td>
        )
    }
    console.log(line);
    return (<tr>{line}</tr>);
    
}


function line(start)
{
    let line=[];
    for (let i = 0; i <8; i++) {
        line.push((start) ? <td className="black"></td> : <td className="white"></td>)
        start=!start;
    }
    return line;
}