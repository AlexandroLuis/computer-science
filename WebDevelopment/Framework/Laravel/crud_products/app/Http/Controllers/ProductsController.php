<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Product;
use App\Models\Store;

class ProductsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $products = Product::all();
        $store = Store::all();

        return view('products.index', compact('products', 'store'));
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        $store = Store::all();

        return view('products.create', compact('store'));
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {     
        $request->validate([
            'name' => 'required|max:60|min:3|string',
            'value' => 'required|max:6|min:2|integer',
        ]);

        $input = $request->all();
        Product::create($input);
        return redirect('products')->with('flash_message', 'products Addedd!');  
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $products = Product::find($id);
        $store = Store::find($id);

        return view('products.show', compact('products', 'store'));
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        $products = Product::find($id);
        $store = Store::find($id);

        return view('products.edit', compact('products', 'store'));
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        $products = Product::find($id);
        $input = $request->all();
        $products->update($input);
        return redirect('products')->with('flash_message', 'products Updated!');  
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        Product::destroy($id);
        return redirect('products')->with('flash_message', 'products deleted!'); 
    }
}
