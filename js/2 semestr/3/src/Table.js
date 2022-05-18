import { useState } from "react"
import "./table.css"


function Table() {
    let [data, useData] = useState([
        {
            name: "Butter", price: 0.9, amount: 99,
            image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: true, discount: 0.1,
        },
        {
            name: "Fancy", price: 10, amount: 5,
            image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.2,
        },
        {
            name: "Cream", price: 3.9, amount: 32, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.01,
        },
        {
            name: "Milk", price: 2.9, amount: 86, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: true, discount: 0.03,
        },
        {
            name: "Yoghurt", price: 2.4, amount: 12, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: true, discount: 0.07,
        },
    ]);

    let [values, useValues] = useState([1, -1]);
    let [environment, useEnvironment] = useState();

    let table = [];

    let sorting = (now, prev) => {
        if (now[environment] < prev[environment]) return values[0]
        if (now[environment] > prev[environment]) return values[1]
        return 0
    }

    for (let i = 0; i < data.length; i++) {
        table.push(
            <tr key={i}>
                <td>{data[i].name}</td>
                <td>{data[i].price}</td>
                <td>{data[i].amount}</td>
                <td><img src={data[i].image} /></td>
                <td>{data[i].description}</td>
                <td>{data[i].isNew ? "новый товар" : "не новый"}</td>
                <td>{Math.round(data[i].discount * 100)}%</td>
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
                    <th onClick={Sorting}>image</th>
                    <th onClick={Sorting}>description</th>
                    <th onClick={Sorting}>is New?</th>
                    <th onClick={Sorting}>discount</th>
                </tr>
                {table}
            </tbody>
        </table>
    );

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
            case 'is New?':
                Change("isNew");
                break;
            case 'discount':
                Change("discount");
                break;
        }
    }
}
export default Table;