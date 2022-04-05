import React, { useState } from "react"
import "./table.css"


function Table() {
    let [data, useData] = useState([
        { name: "Butter", price: 0.9, amount: 99 },
        { name: "Cheese", price: 4.9, amount: 20 },
        { name: "Fancy", price: 10, amount: 5 },
        { name: "Cream", price: 3.9, amount: 32 },
        { name: "Milk", price: 2.9, amount: 86 },
        { name: "Yoghurt", price: 2.4, amount: 12 },
    ]);

    let [values, useValues] = useState([1, -1]);
    let [environment, useEnvironment] = useState();

    let table = [];

    let sorting = (now, prev) => {
        if (now[environment] < prev[environment]) return values[0]
        if (now[environment] > prev[environment]) return values[1]
        return 0
    }

    /*let buf = [
        { name: "Butter", price: 0.9, amount: 99 },
        { name: "Cheese", price: 4.9, amount: 20 },
        { name: "Fancy", price: 10, amount: 5 },
        { name: "Cream", price: 3.9, amount: 32 },
        { name: "Milk", price: 2.9, amount: 86 },
        { name: "Yoghurt", price: 2.4, amount: 12 },
    ];*/

    for (let i = 0; i < data.length; i++) {
        table.push(
            <tr key={i}>
                <td>{data[i].name}</td>
                <td>{data[i].price}</td>
                <td>{data[i].amount}</td>
            </tr>
        )
    }

    return (
        <table>
            <tbody>
                <tr>
                    <th onClick={Sorting}>Name</th>
                    <th onClick={Sorting}>Price</th>
                    <th onClick={Sorting}>Amount</th>

                </tr>
                {table}
            </tbody>
        </table>
    );

    // function SortName() {
    // console.log(values, "start")

    //     useEnvironment("name")
    //     Change()
    // console.log(values)

    // let test = JSON.parse(JSON.stringify(buf));


    // console.log(values, "end")
    // }
    // function SortPrice() {
    //     useEnvironment("price")
    //     Change()
    // }
    // function SortAmount() {
    //     useEnvironment("amount")
    //     Change()
    // }


    function Change(environment) {
        useEnvironment(environment)
        useData((prev) => prev.sort(sorting));
        useValues((prev) => [prev[1], prev[0]]);
    }

    function Sorting(event) {
        switch (event.target.innerHTML) {
            case 'Name':
                Change("name");
                break;
            case 'Price':
                Change("price");
                break;
            case 'Amount':
                Change("amount");
                break;
        }
    }
}
export default Table;