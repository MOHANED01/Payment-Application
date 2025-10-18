<h1>📌 Payment Application (ATM System Simulation)</h1>
<p>
  A layered <strong>Payment Application</strong> written in <strong>C</strong> that simulates the core logic of an <strong>ATM transaction system</strong>.
  It models the interaction between <strong>Card, Terminal, and Server</strong> modules — validating transactions, card details, and account balances.
</p>

<hr />

<h2>📌 Project Overview</h2>
<p>
  This project implements a <strong>console-based simulation</strong> of an embedded payment system that control the workflow of an ATM device.
  It is designed with a focus on <strong>modular programming</strong>, <strong>structured data flow</strong>, and <strong>secure transaction validation</strong>.
</p>

<h3>📌 Objectives</h3>
<ul>
  <li>Develop a transaction processing system with <strong>card, terminal, and server modules</strong>.</li>
  <li>Ensure <strong>secure validation</strong> for card number, expiry, and account balance.</li>
  <li>Design using a <strong>layered architecture</strong> for clarity and scalability.</li>
  <li>Simulate real-world <strong>ATM interaction logic</strong> via the command-line interface.</li>
</ul>

<hr />

<h2>📌 System Architecture</h2>
<pre><code>          ┌──────────────────────────┐
          │       Payment App        │
          │ ──────────────────────── │
          │     Application Layer    │
          │     Server Module        │
          │     Terminal Module      │
          │     Card Module          │
          └──────────────────────────┘
                     │
                     ▼
          [User] → [Card] → [Terminal] → [Server]
</code></pre>

<hr />

<h2>📌 Features</h2>
<ul>
  <li>Card data input and validation (Name, PAN, Expiry Date).</li>
  <li>Transaction amount entry and verification against balance.</li>
  <li>Expiry date check for card validity.</li>
  <li>Balance check for sufficient funds.</li>
  <li>Transaction logging in local memory.</li>
  <li>Fully modular design: <strong>Card → Terminal → Server</strong> layers.</li>
</ul>

<hr />

<h2>📌 Technical Specifications</h2>
<table>
  <thead>
    <tr><th>Component</th><th>Details</th></tr>
  </thead>
  <tbody>
    <tr><td><strong>Programming Language</strong></td><td> C</td></tr>
    <tr><td><strong>Toolchain</strong></td><td>GCC / Code::Blocks</td></tr>
    <tr><td><strong>System Type</strong></td><td>Console-based simulation (PC-hosted)</td></tr>
    <tr><td><strong>Architecture</strong></td><td>Layered (Card → Terminal → Server → App)</td></tr>
  </tbody>
</table>

<hr />

<h2>📌 How It Works</h2>
<ol>
  <li><strong>Card Module:</strong>
    <ul>
      <li>Collects user card information (Name, PAN, Expiry Date).</li>
      <li>Validates PAN format using algorithm.</li>
      <li>Ensures card is not expired.</li>
    </ul>
  </li>
  <li><strong>Terminal Module:</strong>
    <ul>
      <li>Prompts user for transaction amount and date.</li>
      <li>Validates transaction date and amount limits.</li>
      <li>Passes details to the server for approval.</li>
    </ul>
  </li>
  <li><strong>Server Module:</strong>
    <ul>
      <li>Verifies card existence in the accounts database.</li>
      <li>Checks available balance.</li>
      <li>Approves or declines the transaction.</li>
      <li>Logs the result (Approved / Declined).</li>
    </ul>
  </li>
</ol>

<hr />

<h2>📌 Example Run</h2>
<pre><code>----- Welcome to Payment Application -----
Enter Card Holder Name: Mohaned Hossam
Enter Card Expiry Date (MM/YY): 07/25
Enter Primary Account Number: 4523487198236531
Enter Transaction Date (DD/MM/YYYY): 18/10/2023
Enter Transaction Amount: 200.00
Transaction Approved 
-----------------------------------------
</code></pre>

<hr />

<h2>📌 Testing &amp; Validation</h2>
<ul>
  <li>Tested with multiple valid and invalid card entries.</li>
  <li>Verified correct responses for expired cards and insufficient funds.</li>
  <li>Validated transaction limits and balance checks.</li>
  <li>All modules unit-tested independently for reliability.</li>
</ul>

<hr />

<h2>📌 Build &amp; Run Instructions</h2>

<h3>Requirements</h3>
<ul>
  <li><strong>GCC compiler</strong> or <strong>Code::Blocks IDE</strong></li>
  <li>Command-line terminal</li>
</ul>



<hr />

<h2>📌 Future Enhancements</h2>
<ul>
  <li>Implement <strong>PIN authentication</strong> for user verification.</li>
  <li>Add <strong>file-based database</strong> for persistent transactions.</li>
  <li>Integrate <strong>encryption</strong> for secure data handling.</li>
  <li>Extend with <strong>GUI interface</strong> for better user experience.</li>
</ul>

<hr />

<h2>📌 References</h2>
<ul>
  <li>EGYFWD Embedded Systems Nanodegree – Payment System Project</li>
 
</ul>

