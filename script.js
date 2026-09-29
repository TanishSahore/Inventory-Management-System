// ===============================
// Inventory Management System
// ===============================

let products = JSON.parse(localStorage.getItem("products")) || [];

let editIndex = -1;

// Load Data
displayProducts();
updateDashboard();

// ===============================
// Add Product
// ===============================

function addProduct() {

    const name = document.getElementById("name").value.trim();
    const category = document.getElementById("category").value.trim();
    const price = parseFloat(document.getElementById("price").value);
    const quantity = parseInt(document.getElementById("quantity").value);

    if (name === "" || category === "" || isNaN(price) || isNaN(quantity)) {
        alert("Please fill all fields!");
        return;
    }

    const product = {
        id: Date.now(),
        name: name,
        category: category,
        price: price,
        quantity: quantity
    };

    if (editIndex == -1) {

        products.push(product);

        alert("Product Added Successfully!");

    } else {

        product.id = products[editIndex].id;

        products[editIndex] = product;

        editIndex = -1;

        alert("Product Updated Successfully!");

    }

    saveData();

    displayProducts();

    updateDashboard();

    clearForm();

}

// ===============================
// Display Products
// ===============================

function displayProducts() {

    let table = "";

    products.forEach((product, index) => {

        table += `
        <tr>

        <td>${product.id}</td>

        <td>${product.name}</td>

        <td>${product.category}</td>

        <td>₹${product.price}</td>

        <td>${product.quantity}</td>

        <td>

        <button
        class="btn btn-warning btn-sm"
        onclick="editProduct(${index})">

        ✏ Edit

        </button>

        <button
        class="btn btn-danger btn-sm"
        onclick="deleteProduct(${index})">

        🗑 Delete

        </button>

        </td>

        </tr>
        `;

    });

    document.getElementById("productTable").innerHTML = table;

}

// ===============================
// Delete
// ===============================

function deleteProduct(index) {

    if (confirm("Delete this Product?")) {

        products.splice(index, 1);

        saveData();

        displayProducts();

        updateDashboard();

    }

}

// ===============================
// Edit
// ===============================

function editProduct(index) {

    editIndex = index;

    document.getElementById("name").value = products[index].name;

    document.getElementById("category").value = products[index].category;

    document.getElementById("price").value = products[index].price;

    document.getElementById("quantity").value = products[index].quantity;

    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });

}

// ===============================
// Search
// ===============================

function searchProduct() {

    const value = document
        .getElementById("search")
        .value
        .toLowerCase();

    const rows = document.querySelectorAll("#productTable tr");

    rows.forEach(row => {

        row.style.display = row.innerText
            .toLowerCase()
            .includes(value)
            ? ""
            : "none";

    });

}

// ===============================
// Save LocalStorage
// ===============================

function saveData() {

    localStorage.setItem("products", JSON.stringify(products));

}

// ===============================
// Dashboard
// ===============================

function updateDashboard() {

    let totalProducts = products.length;

    let inventoryValue = 0;

    let lowStock = 0;

    let categorySet = new Set();

    products.forEach(product => {

        inventoryValue += product.price * product.quantity;

        if (product.quantity < 5) {

            lowStock++;

        }

        categorySet.add(product.category);

    });

    document.getElementById("totalProducts").innerHTML = totalProducts;

    document.getElementById("inventoryValue").innerHTML = inventoryValue;

    document.getElementById("lowStock").innerHTML = lowStock;

    document.getElementById("categories").innerHTML = categorySet.size;

}

// ===============================
// Clear Form
// ===============================

function clearForm() {

    document.getElementById("name").value = "";

    document.getElementById("category").value = "";

    document.getElementById("price").value = "";

    document.getElementById("quantity").value = "";

}

// ===============================
// Enter Key Support
// ===============================

document.addEventListener("keypress", function (e) {

    if (e.key === "Enter") {

        addProduct();

    }

});

// ===============================
// Welcome Message
// ===============================

console.log("Inventory Management System Loaded Successfully");